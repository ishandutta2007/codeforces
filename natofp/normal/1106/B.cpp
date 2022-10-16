#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool por(pair<long long int,long long int> a,pair<long long int,long long int> b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    long long int * a=new long long int[n+1];
    long long int sum=0;
    for(int i=1;i<=n;i++) {cin>>a[i];  sum+=a[i];}
    long long int * c=new long long int[n+1];
    vector<pair<long long int,long long int> > xd;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        xd.push_back({c[i],i});
    }
    sort(xd.begin(),xd.end(),por);
    int wsk=0;
    while(m--)
    {
        long long int cost=0;
        long long int t,d; cin>>t>>d;
        if(d<=a[t])
        {
            a[t]-=d;
            cost=d*c[t];
            cout<<cost<<endl; continue;
        }
        else
        {
            cost+=a[t]*c[t];
            d-=a[t];
            a[t]=0;
            while(d>0)
            {
                while(wsk<n && a[xd[wsk].second]==0LL) wsk++;
                if(wsk==n) {cout<<0<<endl; break;}
                else
                {
                    int idx=xd[wsk].second;
                    if(d<=a[idx])
                    {
                        a[idx]-=d;
                        cost+=d*c[idx];
                        cout<<cost<<endl; break;
                    }
                    else
                    {
                        cost+=a[idx]*c[idx];
                        d-=a[idx];
                        a[idx]=0;
                    }
                }
            }
        }

    }
    return 0;
}