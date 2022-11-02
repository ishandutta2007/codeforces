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

int x[300007];
char s[300007];
int ans[300007];
int n,m;

void solve(vector<pair<int,pair<char,int>>> v)
{
    vector<pair<int,int>>qr,ql;
    for(auto z:v)
    {
        if(z.nd.st=='R') qr.pb({z.st,z.nd.nd});
        else
        {
            if(sz(qr)>0)
            {
                int d=(z.st-qr.back().st)/2;
                ans[z.nd.nd]=d;
                ans[qr.back().nd]=d;
                qr.pop_back();
            }
            else ql.pb({z.st,z.nd.nd});
        }
    }
    for(int i=1; i<sz(ql); i+=2)
    {
        ans[ql[i-1].nd]=ql[i-1].st+(ql[i].st-ql[i-1].st)/2;
        ans[ql[i].nd]=ql[i-1].st+(ql[i].st-ql[i-1].st)/2;
    }
    for(int i=sz(qr)-2; i>=0; i-=2)
    {
        ans[qr[i+1].nd]=m-qr[i+1].st+(qr[i+1].st-qr[i].st)/2;
        ans[qr[i].nd]=m-qr[i+1].st+(qr[i+1].st-qr[i].st)/2;
    }
    if(sz(ql)%2==1&&sz(qr)%2==1)
    {
        ans[ql.back().nd]=(m+ql.back().st+m-qr[0].st)/2;
        ans[qr[0].nd]=(m+ql.back().st+m-qr[0].st)/2;
    }
}


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
        cin>>n>>m;
        vector<pair<int,pair<char,int>>>v1,v2;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++) cin>>s[i];
        for(int i=1;i<=n;i++)
        {
            ans[i]=-1;
            if(x[i]%2==1) v1.pb({x[i],{s[i],i}});
            else v2.pb({x[i],{s[i],i}});
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        solve(v1);
        solve(v2);
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}