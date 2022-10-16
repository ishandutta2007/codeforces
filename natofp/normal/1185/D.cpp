#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;
vector<pair<int,int> > a;
int n;
bool czy(int start,int kon)
{
    long long int d=a[start+1].first-a[start].first;
    for(int i=start+1;i<=kon;i++)
    {
        if(a[i].first-a[i-1].first!=d) return false;
    }
    return true;
}


int proba()
{
    long long int sum=a[n-1].first-a[0].first;
    int ile=n-1;
    if(sum%(ile-1)!=0) return -1;
    long long int r=sum/(ile-1);
    int idx=-1;
    for(int i=1;i<n;i++)
    {
        if(a[i].first-a[i-1].first!=r)
        {
            idx=i;
            break;
        }
    }
    int wsk=0;
    for(int i=0;i<n;i++)
    {
        if(i==idx) continue;
        if(a[i].first!=a[0].first+(long long int)wsk*r) return -1;
        wsk++;
    }
    return a[idx].second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a.push_back({x,i+1});
    }
    sort(a.begin(),a.end());
    if(n==2)
    {
        cout<<1<<endl;
        return 0;
    }
    if(czy(1,n-1))
    {
        cout<<a[0].second<<endl;
        return 0;
    }
    if(czy(0,n-2))
    {
        cout<<a[n-1].second<<endl;
        return 0;
    }
    int xd=proba();
    cout<<xd<<endl;

    return 0;
}