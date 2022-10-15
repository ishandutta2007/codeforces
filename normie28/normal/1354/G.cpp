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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

#define bi BigInt
typedef long long ll;
#define pi 3.1415926535897
//------START-----------//

    seed_seq seq{
        (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
        (uint64_t) __builtin_ia32_rdtsc(),
        (uint64_t) (uintptr_t) make_unique<char>().get()
    };
    mt19937 rng(seq);

ll get_rand(ll l, ll r)
{
    return uniform_int_distribution<int>(l,r)(rng);
}
ll n,m,i,j,k,u,v,t,t1,a,b,l,r,ress=0;
set<ll> se;
ll cntn=0;
ll dfsl[1000001],indeg[1000001],dfsr[1000001],arr[1000001];
ll cmax[1000001],dep[1000001];
vector<ll> aa,bb;
int get (vector<ll> a, vector<ll> b)
{
    cout<<"? "<<a.size()<<' '<<b.size()<<endl;
    for (ll g : a) cout<<g<<' '; cout<<endl;
    for (ll g : b) cout<<g<<' '; cout<<endl;
    string res;
    cin>>res;
    if (res=="SECOND") return -1;
    else if (res=="FIRST") return 1;
    else if (res=="EQUAL") return 0;
    else exit(0);
}
ll bs (ll l, ll r)
{
//	cout<<"bs "<<l<<' '<<r<<endl;
	if (l==r) return l;
	ll mid=(l+r)/2;
	aa.clear();
	bb.clear();
	for (ll i=l;i<=mid;i++) aa.push_back(i-l+1);
	for (ll i=l;i<=mid;i++) bb.push_back(i);
	if (get(aa,bb)==1) return bs(l,mid); else return bs(mid+1,r);
}
//------END-----------//
int main()
{
//    ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n;
        cin>>m;
        int done=0;
        for (i=1;i<=30;i++)
        {
            u=get_rand(2,n);
            if (get({1},{u})==-1) {cout<<"! 1"<<endl; done=1; break;}
        }
        if (done) continue;
        int j=1;
        while(j*2<=n)
        {
            aa.clear();
            bb.clear();
            for (i=1;i<=j;i++) aa.push_back(i);
            for (i=1;i<=j;i++) bb.push_back(i+j);
            if (get(aa,bb)==1) break;
            else j*=2;
		}
		ll op;
		if (j*2>n) op=bs(j+1,n);
		else op=bs(j+1,2*j);
		cout<<"! "<<op<<endl;
    }
}