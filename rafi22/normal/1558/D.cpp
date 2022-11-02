#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define ll long long
#define ld long double
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

int fac[400007];
int inv[400007];

int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int npok(int n,int k) {return fac[n]*inv[k]%mod*inv[n-k]%mod;}

const bool multi=1;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mod=mod1;
    ordered_set S;
    for(int i=1;i<=200000;i++) S.insert(i);
    fac[0]=1;
    for(int i=1;i<=400000;i++) fac[i]=fac[i-1]*i%mod;
    inv[400000]=pot(fac[400000],mod-2);
    for(int i=400000-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>V(m);
        for(int i=0;i<m;i++) cin>>V[i].st>>V[i].nd;
        set<int>C;
        vector<int>del;
        for(int i=m-1;i>=0;i--)
        {
            int nx=*(S.find_by_order(V[i].nd));
            if(nx<=n) C.insert(nx);
            int x=*S.find_by_order(V[i].nd-1);
            del.pb(x);
            S.erase(x);
        }
        cout<<npok(n+n-1-sz(C),n)<<endl;
        for(auto x:del) S.insert(x);
    }

    return 0;
}