
// Problem : B. Game with modulo
// Contest : Codeforces - Codeforces Round #534 (Div. 1)
// URL : https://codeforces.com/contest/1103/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
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
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define bi BigInt
typedef long long ll;
//---------END-------//

const int N = 1e6 + 5;
const int mod = 1e9 + 7;
 
void add(int & x, int y) {
	if ((x += y) >= mod)
		x -= mod;
}
void sub(int & x, int y) {
	if ((x -= y) < 0)
		x += mod;
}
int dpZeros[N][3];
deque<int> svDp[2];
int sumDp[2];
int dp[3][20];
int main() {
    fio;
	int n, k;
 
	cin >> n >> k;
 
	string str;
	cin >> str;
	str = "#" + str;
 
	dpZeros[0][0] = 1;
 
	for (int i = 1; i <= n; i++) {
		int b4SumDp[2] = {sumDp[0], sumDp[1]};
		if (str[i] != 'W') {
			svDp[0].push_front(dpZeros[i - 1][0]);
			add(sumDp[0], dpZeros[i - 1][0]);
			if (svDp[0].size() == k) {
				add(dpZeros[i][1], svDp[0].back());
				sub(sumDp[0], svDp[0].back());
				svDp[0].pop_back();
			}
			add(dpZeros[i][1], dpZeros[i - 1][1]);
			add(dpZeros[i][1], b4SumDp[1]);
			if (str[i] != 'X') {
				svDp[1].clear();
				sumDp[1] = 0;
			}
			dpZeros[i][2] = dpZeros[i - 1][2];
		}
		if (str[i] != 'B') {
			add(dpZeros[i][0], dpZeros[i - 1][0]);
			add(dpZeros[i][0], b4SumDp[0]);
			if (str[i] != 'X') {
				svDp[0].clear();
				sumDp[0] = 0;
			}
			svDp[1].push_front(dpZeros[i - 1][1]);
			add(sumDp[1], dpZeros[i - 1][1]);
			if (svDp[1].size() == k) {
				add(dpZeros[i][2], svDp[1].back());
				sub(sumDp[1], svDp[1].back());
				svDp[1].pop_back();
			}
			add(dpZeros[i][2], dpZeros[i - 1][2]);
		}
	}
 
	cout << dpZeros[n][2] << '\n';
}