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
int mod=998244353;
int mod1=998244353;

const bool multi=0;

int p[200007];
bool is[200007];
pair<int,int> seg[200007*4];
int pot=1;

int po(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int inv=po(100,mod-2);

pair<int,int> que(int v,int l,int r,int a,int b)
{
    if(l>b||r<a) return {0,1};
    if(a<=l&&b>=r) return seg[v];
    pair<int,int>p1=que(2*v,l,(l+r)/2,a,b),p2=que(2*v+1,(l+r)/2+1,r,a,b);
    return {(p1.st+p2.st*p1.nd)%mod,p1.nd*p2.nd%mod};
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
        mod=mod1;
        int n,q,a,ans=0;
        cin>>n>>q;
        while(pot<n) pot*=2;
        for(int i=1;i<=n;i++) cin>>p[i];
        for(int i=1;i<=n;i++) seg[i+pot-1]={1,p[i]*inv%mod};
        for(int i=pot-1;i>0;i--)
        {
            seg[i].st=(seg[2*i].st+seg[2*i+1].st*seg[2*i].nd)%mod;
            seg[i].nd=seg[2*i].nd*seg[2*i+1].nd%mod;
        }
        set<int>S;
        S.insert(1);
        S.insert(n+1);
        pair<int,int>p=que(1,1,pot,1,n);
        ans=po(p.nd,mod-2)*p.st%mod;
        while(q--)
        {
            cin>>a;
            if(!is[a])
            {
                int l=*--S.upper_bound(a),r=*S.upper_bound(a);
                p=que(1,1,pot,l,r-1);
                ans=(ans-po(p.nd,mod-2)*p.st%mod+mod)%mod;
                S.insert(a);
                p=que(1,1,pot,l,a-1);
                ans=(ans+po(p.nd,mod-2)*p.st%mod)%mod;
                p=que(1,1,pot,a,r-1);
                ans=(ans+po(p.nd,mod-2)*p.st%mod)%mod;
            }
            else
            {
                S.erase(a);
                int l=*--S.upper_bound(a),r=*S.upper_bound(a);
                p=que(1,1,pot,l,a-1);
                ans=(ans-po(p.nd,mod-2)*p.st%mod+mod)%mod;
                p=que(1,1,pot,a,r-1);
                ans=(ans-po(p.nd,mod-2)*p.st%mod+mod)%mod;
                p=que(1,1,pot,l,r-1);
                ans=(ans+po(p.nd,mod-2)*p.st%mod)%mod;
            }
            is[a]=!is[a];
            cout<<ans<<endl;
        }
    }

    return 0;
}