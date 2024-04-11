// Problem: Median Sort
// Contest: Google Coding Competitions - Qualification Round 2021 - Code Jam 2021
// URL: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284
// Memory Limit: 1024 MB
// Time Limit: 40000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
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
#define INF (ll(998244353))
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

//---------END-------//
int main() {
    fio;
	int n, k, l;
	cin>>n>>k>>l;
	
	vector<int> x(k), a(l);
	
	for(int i=0;i<k;i++)
		cin >> x[i];
	
	for(int i=0;i<l;i++)
		cin >> a[i];
	
	for(int i=0;i<l;i++)
		a.push_back(-a[i]);
	
	
	map<int, vector<int> > reach;
	
	{
		vector<int> bases;
		for(auto c : x) {
			bases.push_back(c-1);
			bases.push_back(c);
		}
		
		for(auto b : bases) {
			vector<int> cost(n+1, INF);
			
			vector<int> front(1, b);
			cost[b] = 0;
			
			for(size_t i=0;i<front.size();i++) {
				
				for(auto mov : a) {
					int next = front[i] + mov;
					
					if(next >= 0 && next <= n && cost[next] > cost[front[i]]+1){
						cost[next] = cost[front[i]]+1;
						front.push_back(next);
					}
				}
			}
			reach[b] = cost;
		}
	}
	int result = INF;
	
	for(int orient = 0; orient < (1<<k); orient++) {
		vector<bool> dir(k);
		
		for(int i=0;i<k;i++)
			dir[i] = ( (orient & (1<<i)) != 0);
		
		
		vector<int> dp(1<<k, INF);
		dp[0] = 0;
		
		for(int comb = 0; comb < (1<<k)-1; comb++) {
			if(dp[comb] == INF)
				continue;
			
			int cind = 0;
			for(int i=0;i<k;i++)
				if((comb & (1<<i)) != 0)
					cind++;
			
			int cur = x[cind];
			
			for(int j=0;j<k;j++)
				if((comb & (1<<j)) == 0)
					dp[comb + (1<<j)] = min(dp[comb+(1<<j)], dp[comb] + reach[cur - 1 + dir[cind]] [x[j] - dir[j]]);
			
		}
		
		result = min(result, dp[(1<<k)-1]);
	}
	
	if (result == INF)
		cout<<-1;
	else
		cout<<result;
}