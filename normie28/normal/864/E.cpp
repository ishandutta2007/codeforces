#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile                     \
    freopen(FILE_IN, "r", stdin); \
    freopen(FILE_OUT, "w", stdout)
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define nfio    \
    cin.tie(0); \
    cout.tie(0)
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
#define ord(a, b, c) ((a >= b) and (b >= c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1) << x)
#define pii pair<int, int>
#define piii pair<int, pii>
#define For(i, __, ___) for (int i = __; i <= ___; i++)
#define Rep(i, __, ___) for (int i = __; i >= ___; i--)
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
 
const int N = 1e3;
const int INF = 2e9;
 
struct Item{
	int t,d,p,id;
 
	bool operator < (const Item& x) const{
		return d < x.d;	
	}
};
 
Item w[N];
int dp[2001];
vector<int> ans[2001];
 
int main(){
    ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	for(int i=1; i<=n; i++){
		cin>>w[i].t>>w[i].d>>w[i].p;
		w[i].id = i;
	}
	sort(w + 1, w + n + 1);
	
	for(int i=1; i<=n; i++){
		for(int time = w[i].d-1; w[i].t <= time; time-- ){
			if(dp[time] < dp[time - w[i].t] + w[i].p){
				dp[time] = dp[time - w[i].t] + w[i].p;
				ans[time] = ans[time - w[i].t];
				ans[time].push_back(w[i].id);
			}
		}
	}
	vector<int> what;
	vector<int>& q = what;
	int best = 0;
	for(int i=1; i<=2000; i++){
		if(best < dp[i]){
			best = dp[i];
			q = ans[i];
		}
	}
	cout<<best<<"\n";
	cout<<q.size()<<"\n";
	for(auto p : q){
		cout<<p<<" ";
	}
	cout<<"\n";
}