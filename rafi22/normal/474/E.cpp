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

const bool multi=0;

int a[100007];
int pos[100007];
int pos1[100007];
int ord[100007];
pair<int,int> seg[400007];
int pot=1;
int DP[100007];
int skad[100007];

pair<int,int> que(int v,int a,int b,int l,int r)
{
    if(a<=l&&b>=r) return seg[v];
    if(l>b||r<a) return {0,0};
    return max(que(2*v,a,b,l,(l+r)/2),que(2*v+1,a,b,(l+r)/2+1,r));
}

void ins(int u,int v)
{
    u+=pot-1;
    seg[u]={v,u-pot+1};
    while(u>1)
    {
        u/=2;
        seg[u]=max(seg[2*u],seg[2*u+1]);
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
        int n,d;
        cin>>n>>d;
        vector<pair<int,int>> v;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            v.pb({a[i],i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<sz(v);i++)
        {
            pos[v[i].nd]=i+1;
            ord[i+1]=v[i].st;
            pos1[i+1]=v[i].nd;
        }
        while(pot<n) pot*=2;
        for(int i=1;i<2*pot;i++) seg[i]={0,0};
        ins(pos[1],1);
        for(int i=2;i<=n;i++)
        {
            //for(int j=pot;j<2*pot;j++) cout<<seg[j].st<<" ";
            //cout<<endl;
            int l=1,r=pos[i]-1,sr,L=0,R=n+1;
            while(l<=r)
            {
                sr=(l+r)/2;
                if(ord[pos[i]]-ord[sr]>=d)
                {
                    l=sr+1;
                    L=sr;
                }
                else  r=sr-1;
            }
            l=pos[i]+1,r=n;
            while(l<=r)
            {
                sr=(l+r)/2;
                if(ord[sr]-ord[pos[i]]>=d)
                {
                    R=sr;
                    r=sr-1;
                }
                else l=sr+1;
            }
            pair<int,int>p=max(que(1,1,L,1,pot),que(1,R,n,1,pot));
            DP[i]=p.st+1;
            skad[i]=pos1[p.nd];
            ins(pos[i],DP[i]);
        }
        DP[1]=1;
        int res=0,p;
        for(int i=1;i<=n;i++)
        {
            if(DP[i]>res)
            {
                res=DP[i];
                p=i;
            }
        }
        cout<<res<<endl;
        vector<int>ans;
        while(p>0)
        {
            ans.pb(p);
            p=skad[p];
        }
        reverse(ans.begin(),ans.end());
        for(auto x:ans) cout<<x<<" ";
    }

    return 0;
}