#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,k;
        cin>>n;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>k;
            int mx=0,a;
            for(int j=0;j<k;j++)
            {
                cin>>a;
                mx=max(mx,a-j);
            }
            v[i]={mx+1,k};
        }
        sort(v.begin(),v.end());
        int l=1,r=1000000007,sr,ans;
        while(l<=r)
        {
            sr=(l+r)/2;
            bool ok=1;
            int p=sr;
            for(auto x:v)
            {
                if(p<x.st) ok=0;
                p+=x.nd;
            }
            if(ok)
            {
                ans=sr;
                r=sr-1;
            }
            else l=sr+1;
        }
        cout<<ans<<endl;
    }


    return 0;
}