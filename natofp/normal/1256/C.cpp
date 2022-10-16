#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax=1e3+5;

int xd[nax];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a;
    int sum=0;
    int n,m,d; cin>>n>>m>>d;
    for(int i=0;i<m;i++)
    {
        int x; cin>>x; a.push_back(x); sum+=x;
    }
    int last=0;
    int j=-1;
    bool ok = true;
    for(int i=1;i<=n;i++)
    {
        int zostalo=n-i+1;
        if(zostalo==sum)
        {
            j++;
            int ile=a[j];
            for(int x=i;x<i+ile;x++) xd[x]=j+1;
            last=i+ile-1;
            sum-=ile;
            i+=ile-1;
            continue;
        }
        if(i-last<d)
        {
            continue;
        }
            if(j==m-1)
            {
                ok = false; break;
            }
            j++;
            int ile=a[j];
            for(int x=i;x<i+ile;x++) xd[x]=j+1;
            last=i+ile-1;
            sum-=ile;
            i+=ile-1;
            continue;


    }
    if(ok==false)
    {
        cout<<"NO"<<endl; return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++) cout<<xd[i]<<" ";
    return 0;
}