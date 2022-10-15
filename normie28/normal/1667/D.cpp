#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.5
	Changes:
    Added warning against using pragmas on USACO.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
// template<typename T>
// __attribute__((always_inline)) void chkmin(T& a, const T& b) {
//     a=(a<b)?a:b;
// }

// template<typename T>
// __attribute__((always_inline)) void chkmax(T& a, const T& b) {
//     a=(a>b)?a:b;
// }
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
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

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
#endif
vector<int> gt[200001];

vector<int> buc[200001][3];
vector<int> ord[200001];
vector<pii(int)> fin;
int n,m,i,j,k,t,t1,u,v,a,b,res;
int dp[200001][2];
int par[200001];

void dfs(int x, int p) {
	if (gt[x].size()==1 && x-1) {
		dp[x][par[x]]=1;
	}
	else {
		int cnt[2]={0,0};
		int lw[2]={0,0};
		int fail=0;
		cnt[0]=gt[x].size()/2;
		cnt[1]=gt[x].size()-cnt[0];
		for (auto g : gt[x]) if (g-p) {
			dfs(g,x);
			if (dp[g][0]==0 && dp[g][1]==0) {
				fail=1;
			}
			else if (dp[g][0]==0) lw[1]++;
			else if (dp[g][1]==0) lw[0]++;
		}
		if (fail) return;
		if (x==1) {
			if (cnt[0]>=lw[0] && cnt[1]>=lw[1]) res=1;
		}
		else {
			if (cnt[0]-1>=lw[0] && cnt[1]>=lw[1]) dp[x][0]=1;
			if (cnt[0]>=lw[0] && cnt[1]-1>=lw[1]) dp[x][1]=1;
		}
	}
}



void post(int x, int p, int mode) {
	// cout<<"post "<<x<<' '<<p<<' '<<endl;
	if (x!=1) {
		int i,j;
		for (i=0;i<gt[x].size();i++) if (ord[x][i]==p) {
			break;
		}
		for (j=gt[x].size()-1;j>=0;j--) if (j<i) fin.push_back({ord[x][j],x});
		for (j=gt[x].size()-1;j>=0;j--) if (j-i) post(ord[x][j],x,1^(j&1));
	}
}

void pre(int x, int p, int mode) {
	// cout<<"pre "<<x<<' '<<p<<' '<<endl;
	if (x!=1) {
		buc[x][mode].push_back(p);
		for (auto g : gt[x]) if (g-p) {
			if (dp[g][0]==0) {
				buc[x][1].push_back(g);
			}
			else if (dp[g][1]==0) {
				buc[x][0].push_back(g);
			}
			else {
				buc[x][2].push_back(g);
			}
		}
		
		ord[x]=vector<int>(gt[x].size(),0);
		for (int i=0;i<buc[x][1].size();i++) {
			ord[x][i*2]=buc[x][1][i];
		}
		for (int i=0;i<buc[x][0].size();i++) {
			ord[x][i*2+1]=buc[x][0][i];
		}
		int i,j;
		for (i=0;i<gt[x].size();i++) if (!ord[x][i]) {
			ord[x][i]=buc[x][2][j];
			j++;
		}
		for (i=0;i<gt[x].size();i++) if (ord[x][i]==p) {
			break;
		}
		// for (auto g : ord[x]) cout<<g<<' '; cout<<endl;
		for (j=gt[x].size()-1;j>=0;j--) if (j-i) pre(ord[x][j],x,1^(j&1));
		for (j=gt[x].size()-1;j>=0;j--) if (j>i) fin.push_back({ord[x][j],x});
	}
	else {

		for (auto g : gt[x]) if (g-p) {
			if (dp[g][0]==0) {
				buc[x][1].push_back(g);
			}
			else if (dp[g][1]==0) {
				buc[x][0].push_back(g);
			}
			else {
				buc[x][2].push_back(g);
			}
		}
		
		ord[x]=vector<int>(gt[x].size(),0);
		for (int i=0;i<buc[x][1].size();i++) {
			ord[x][i*2]=buc[x][1][i];
		}
		for (int i=0;i<buc[x][0].size();i++) {
			ord[x][i*2+1]=buc[x][0][i];
		}
		int i,j;
		for (i=0;i<gt[x].size();i++) if (!ord[x][i]) {
			ord[x][i]=buc[x][2][j];
			j++;
		}

		for (j=gt[x].size()-1;j>=0;j--)  pre(ord[x][j],x,1^(j&1));
		for (j=gt[x].size()-1;j>=0;j--)  fin.push_back({ord[x][j],x});
		for (j=gt[x].size()-1;j>=0;j--)  post(ord[x][j],x,1^(j&1));

	}
}
int main()
{
	// fio;
	cin>>t;
	for (t1=0;t1<t;t1++) {
		cin>>n;
		for (i=1;i<=n;i++) {
			gt[i].clear();
			dp[i][0]=dp[i][1]=0;
			par[i]=0;
			
			buc[i][0].clear();
			buc[i][1].clear();
			buc[i][2].clear();
			ord[i].clear();
		}
		res=0;
		for (i=1;i<n;i++) {
			cin>>u>>v;
			par[u]^=1;
			par[v]^=1;
			gt[u].push_back(v);
			gt[v].push_back(u);
		}
		dfs(1,1);
		if (res==0) cout<<"NO\n"; else {
			fin.clear();
			cout<<"YES\n";
			pre(1,1,0);
			for (auto g : fin) cout<<g.fi<<' '<<g.se<<endl;
		}
	}
}