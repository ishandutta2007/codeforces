/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
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
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
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
int n,m;
 
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
 
int deg[MAX];
 
set<int> pos[MAX];
set<int> neg[MAX];
 
int ans[MAX];
bool used[MAX]; 
 
vector<int> vv[MAX];
 
bool vis[MAX];
 
int nex(int val, int node){
	val = abs(val);
	for (auto it = pos[val].begin(); it != pos[val].end(); it++){
		if ((*it) != node){
			return (*it);
		}
	}
	for (auto it = neg[val].begin(); it != neg[val].end(); it++){
		if ((*it) != node){
			return (*it);
		}
	}
	exit(1);
}
inline void dfs(int b){
	vis[b] = true;
	for (int i = 0; i < vv[b].size(); i++){
		if (used[abs(vv[b][i])]){
			continue;
		}
		used[abs(vv[b][i])] = true;
		ans[abs(vv[b][i])] = (vv[b][i] < 0);
		if (vis[nex(vv[b][i], b)] == false){
			dfs(nex(vv[b][i], b));
		}
	}
}
 
int main(){
    fio;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int k;
        cin>>k;
		for (int j = 0; j < k; j++){
			int val;
            cin>>val;
			if (val>0)pos[val].insert(i);
			else neg[-val].insert(i);
			vv[i].push_back(val);
		}
	}
	for (int i = 1; i <= m; i++){
		if (neg[i].size() == 0 && pos[i].size() == 1){
			used[i] = true;
			ans[i] = 1;
		}
		if (neg[i].size() == 1 && pos[i].size() == 0){
			used[i] = true;
			ans[i] = 0;
		}
		if (pos[i].size() == 2){
			used[i] = true;
			ans[i] = 1;
		}
		if (neg[i].size() == 2){
			used[i] = true;
			ans[i] = 0;
		}
		if (neg[i].size() == 1 && pos[i].size() == 1){
			if ((*neg[i].begin()) == (*pos[i].begin())){
				used[i] = true;
				ans[i] = 0;
			}
		}
	}
	for (int i = 1; i <= m; i++){
		if (pos[i].size() == 2){
			dfs((*pos[i].begin()));
			dfs((*pos[i].rbegin()));
		}
		if (neg[i].size() == 2){
			dfs((*neg[i].begin()));
			dfs((*neg[i].rbegin()));
		}
		if (neg[i].size() == 0 && pos[i].size() == 1){
			dfs((*pos[i].begin()));
		}
		if (neg[i].size() == 1 && pos[i].size() == 0){
			dfs((*neg[i].begin()));
		}
		if (neg[i].size() == 1 && pos[i].size() == 1){
			if ((*neg[i].begin()) == (*pos[i].begin())){
				dfs((*pos[i].begin()));
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (vis[i] == false){
			for (int j = 0; j < vv[i].size(); j++){
				if (used[abs(vv[i][j])] == false){
					deg[i]++;
				}
			}
			q.push(make_pair(deg[i], i));
		}
	}
	while (!q.empty()){
		pair<int, int> p = q.top();
		q.pop();
		if (vis[p.second])continue;
		vis[p.second] = true;
		int node = p.second;
		vector<pair<int, int> > v;
		for (int i = 0; i < vv[node].size(); i++){
			int go = nex(vv[node][i], node);
			if (used[abs(vv[node][i])])continue;
			v.push_back(make_pair(deg[go], i));
		}
		if (v.size() != deg[node])exit(1);
		sort(v.begin(), v.end(), greater<pair<int, int> >());
		if (v.size() == 0){
            cout<<"NO";
			return 0;
		}
		int go = nex(vv[node][v.back().second], node);
		if (deg[go] <= 1){
            cout<<"NO";
			return 0;
		}
		deg[go]--;
		used[abs(vv[node][v.back().second])] = true;
		ans[abs(vv[node][v.back().second])] = (vv[node][v.back().second] > 0);
		dfs(node);
		q.push(make_pair(deg[go], go));
	}
    cout<<"YES"<<endl;
	for (int i = 1; i <= m; i++){
        cout<<ans[i];
	}
}