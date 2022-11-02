#include <bits/stdc++.h>

#define int long long
#define double long double
//#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int h[300007];
map<int,int>mapa;
int DP[300007];
int lo[300007];
int hi[300007];
int seg[1300007],pot=1;
void ins(int u,int v)
{
    int y=u+pot-1;
    while(y>0)
    {
        seg[y]=v;
        y/=2;
    }
}
int que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(l>b||r<a) return 0;
    return max(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
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
        int n;
        cin>>n;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            cin>>h[i];
            v.pb(h[i]);
        }
        sort(v.begin(),v.end());
        int it=1;
        mapa[v[0]]=1;
        for(int i=1;i<sz(v);i++)
        {
            if(v[i]!=v[i-1]) mapa[v[i]]=++it;
        }
        while(pot<it) pot*=2;
        for(int i=1;i<=n;i++) h[i]=mapa[h[i]];
        ins(h[1],1);
        for(int i=2;i<=n;i++)
        {
            lo[i]=que(1,1,h[i]-1,1,pot);
            hi[i]=que(1,h[i]+1,it,1,pot);
            ins(h[i],i);
            DP[i]=DP[i-1]+1;
            int c=i-1;
            if(h[i-1]>h[i])
            {
                while(c!=0)
                {
                    DP[i]=min(DP[i],DP[c]+1);
                    if(h[c]<=h[i]) break;
                    c=lo[c];
                }
            }
            else
            {
                while(c!=0)
                {
                    DP[i]=min(DP[i],DP[c]+1);
                    if(h[c]>=h[i]) break;
                    c=hi[c];
                }
            }
        }
        cout<<DP[n];
    }


    return 0;
}