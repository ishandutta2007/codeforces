#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

vector<int>fac[1000007];
bool p[1000007];
vector<pair<int,int>>kon[200007];
int a[200007];
int ans[200007];
int last[1000007];

int seg[4*200007];
const int pot=1<<18;

int que(int v)
{
    v+=pot-1;
    int ans=1;
    while(v)
    {
        ans=ans*seg[v]%mod;
        v/=2;
    }
    return ans;
}
void ins(int v,int a,int b,int l,int r,int x)
{
    if(r<a||l>b) return ;
    if(a<=l&&b>=r)
    {
        seg[v]=seg[v]*x%mod;
        return;
    }
    ins(2*v,a,b,l,(l+r)/2,x);
    ins(2*v+1,a,b,(l+r)/2+1,r,x);
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
        for(int i=2;i<=1000000;i++)
        {
            if(p[i]) continue;
            fac[i].pb(i);
            for(int j=2*i;j<=1000000;j+=i)
            {
                p[j]=1;
                int x=j;
                while(x%i==0)
                {
                    fac[j].pb(i);
                    x/=i;
                }
            }
        }
        int n,q;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            int l,r;
            cin>>l>>r;
            kon[r].pb({l,i});
        }
        for(int i=1;i<2*pot;i++) seg[i]=1;
        for(int i=1;i<=n;i++)
        {
            for(auto x:fac[a[i]])
            {
                ins(1,1,last[x],1,pot,x);
                ins(1,last[x]+1,i,1,pot,x-1);
                last[x]=i;
            }
            for(auto j:kon[i]) ans[j.nd]=que(j.st);
        }
        for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    }

    return 0;
}