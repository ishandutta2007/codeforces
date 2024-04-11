#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int suma=0;
long long int res=0;
int roz=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin>>n>>k;
    vector<pair<int,int> > a;
    for(int i=0;i<n;i++)
    {
        int x,y; cin>>x>>y;
        a.push_back({y,x});
    }
    sort(a.begin(),a.end());
    multiset<int> s;
    for(int i=n-1;i>=0;i--)
    {
        int t;
        if(s.size()==0) t=0;
        else t=*s.begin();
        if(roz<k)
        {
            int wstaw=a[i].second;
            suma+=wstaw;
            s.insert(wstaw);
            res=max(res,(long long int)a[i].first*suma);
            roz++;
        }
        else
        {
            int wstaw=a[i].second;
            if(wstaw>t)
            {
                s.erase(s.find(t));
                suma-=t;
                suma+=wstaw;
                s.insert(wstaw);
                res=max(res,(long long int)a[i].first*suma);
            }
        }

    }
    cout<<res;
    return 0;
}