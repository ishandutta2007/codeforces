
// Problem : E. Defining Macros
// Contest : Codeforces - Codeforces Beta Round #7
// URL : https://codeforces.com/problemset/problem/7/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
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
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef vector<int> vi;
//---------END-------//
int n;
string s;
map<string, int> id;
 
int dfs(int l, int r) {
	for(int i = r, cnt = 0; i > l; --i) {
		cnt += (s[i] == ')');
		cnt -= (s[i] == '(');
		if(!cnt && (s[i] == '+' || s[i] == '-')) {
			int L = dfs(l, i - 1), R = dfs(i + 1, r);
			return L && R && (s[i] == '+' || R > 1);
		}
	}
	for(int i = r, cnt = 0; i > l; --i) {
		cnt += (s[i] == ')');
		cnt -= (s[i] == '(');
		if(!cnt && (s[i] == '*' || s[i] == '/')) {
			int L = dfs(l, i - 1), R = dfs(i + 1, r);
			return (L > 1 && (s[i] == '*' ? (R > 1) : (R > 2))) ? 2 : 0;
		}
	}
	if(s[l] == '(') return dfs(l + 1, r - 1) ? 3 : 0;
	return id.count(s.substr(l, r - l + 1)) ? id[s.substr(l, r - l + 1)] : 3;
}
 
int calc() {
	getline(cin, s);
	int n = sz(s), m = 0;
	rep(i, 0, n) if(s[i] != ' ') s[m++] = s[i];
	s.resize(m);
	return dfs(0, m - 1);
}
 
int main() {
	fio;
	cin >> n;
	rep(i, 1, n + 1) {
		string s;
		while(cin >> s) {
			if(s == "define" || s == "#define") break;
		}
		cin >> s;
		id[s] = calc();
	}
	cout << (calc() ? "OK" : "Suspicious") << endl;
}