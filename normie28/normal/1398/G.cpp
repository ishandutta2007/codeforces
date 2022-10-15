/*
khoi orz, go check out his algo
-normie-
Tested with library-checker.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "birds.inp"
#define FILE_OUT "birds.out"
#define prev prv
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef int ll;
#define pi 3.1415926535897
//------START-----------//
ll n,m,i,j,k,u,v,a,b,cnt,ress=0;
vector<ll> gt[1000001]; ll nxt[1000001][26];    
vector<ll> mk[1000001];
vector<pll> res;
string s;
using cd = complex<double>;
const double PI = acos(-1);
ll maxx[1000001];
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;
 
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);
 
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
 
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
//------END-----------//
int main()
{
//    ofile;
    fio;
    cin>>n>>a>>b;
    vector<int> b1(a+1),b2(a+1);
    for (i=0;i<=n;i++)
    {
        cin>>u;
        b1[u]=1;
        b2[a-u]=1;
    }
    vector<int> c=multiply(b1,b2);
    for (i=1;i<=a;i++)
    {
        if (c[a+i])
        {
            u=2*i+2*b;
            for (j=u;j<=1000000;j+=u) maxx[j]=max(maxx[j],u);
        }
    }
    cin>>m;
    for (i=1;i<=m;i++) 
    {
        cin>>u;
        if (maxx[u]==0) cout<<-1; else cout<<maxx[u];
        cout<<' ';
    }
}