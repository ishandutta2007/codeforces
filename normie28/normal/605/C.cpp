
// Problem : C. Freelancer's Dreams
// Contest : Codeforces - Codeforces Round #335 (Div. 1)
// URL : https://codeforces.com/problemset/problem/605/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
//---------END-------//
 
int n, p, q;
pi a[100005];
 
vector<pi> v1, v2;
llf ret;
 
lint ccw(pi a, pi b, pi c){
	int dx1 = b.first - a.first;
	int dy1 = b.second - a.second;
	int dx2 = c.first - a.first;
	int dy2 = c.second - a.second;
	return 1ll * dx1 * dy2 - 1ll * dy1 * dx2;
}
 
int main(){
	fio;
	cin >> n >> p >> q;
	llf ret = 1e19;
	for(int i=0; i<n; i++){
		cin>>a[i].first>>a[i].second;
		ret = min(ret, max((llf) p / a[i].first, (llf) q / a[i].second));
	}
	sort(a, a+n);
	vector<pi> v;
	for(int i=n-1; i>=0; i--){
		while(v.size() >= 2 && ccw(v[v.size()-2], v.back(), a[i]) <= 0){
			v.pop_back();
		}
		v.push_back(a[i]);
	}
	for(int i=0; i+1<v.size(); i++){
		if(ccw(pi(0, 0), v[i], pi(p, q)) > 0 && ccw(pi(0, 0), pi(p, q), v[i+1]) > 0){
			lint a = v[i+1].second - v[i].second;
			lint b = v[i].first - v[i+1].first;
			lint c = (a * v[i].first + b * v[i].second);
			ret = min(ret, (llf) (a * p + b * q) / c);
		}
	}
	cout<<fixed<<setprecision(10)<<(double)ret;
}