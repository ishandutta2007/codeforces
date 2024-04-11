// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;

// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)

//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"

//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))

//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MAX 300001
#define mag 320

//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>

//Quick power of 2.
#define pow2(x) (ll(1)<<x)

//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)

//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
ll n,m,i,j,k,t,t1,u,v,a,b;
const ll MOD=1000000007;
vector<pii(ll)> bruh[100001];
ll res[100001],inn[100001],fac[100001],inv[100001];
ll pw25[100001],pw26[100001],invpw26[100001];
ll bow(ll a, ll x, ll p)
{
    if (!x) return 1;
    ll res=bow(a,x/2,p);
    res*=res;
    res%=MOD;
    if (x%2) res*=a;
    return res%MOD;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    string s;
    cin>>s;
    u=s.length();
    for (i=1;i<=n;i++)
    {
        cin>>a;
        if (a==1)
        {
            cin>>s;
            u=s.length();
        }
        else
        {
            cin>>m;
            bruh[u].push_back({i,m});
            inn[i]=1;
        }
    }
    fac[0]=inv[0]=pw25[0]=pw26[0]=invpw26[0]=1;
    for (i=1;i<=100000;i++)
    {
        fac[i]=(fac[i-1]*i)%MOD;
        inv[i]=bow(fac[i],MOD-2,MOD);
        pw25[i]=(pw25[i-1]*25)%MOD;
        pw26[i]=(pw26[i-1]*26)%MOD;
        invpw26[i]=bow(pw26[i],MOD-2,MOD);
    }
    for (i=1;i<=100000;i++) if (bruh[i].size())
    {
        sort(bruh[i].begin(),bruh[i].end(),[](pii(int) a, pii(int) b){
            return (a.se<b.se);
        });
        u=i-1;
        a=0;
        for (auto g : bruh[i])
        {
            while(u<g.se)
            {
                u++;
                b=fac[u-1];
                b=(b*inv[i-1])%MOD;
                b=(b*inv[u-i])%MOD;
                b=(b*pw25[u-i])%MOD;
                b=(b*invpw26[u])%MOD;
                a=(a+b)%MOD;
            }
            res[g.fi]=(a*pw26[g.se])%MOD;
        }
    }
    for (i=1;i<=n;i++) if (inn[i]) cout<<res[i]<<endl;
}