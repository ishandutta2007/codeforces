// Problem : F. Sonya and Bitwise OR
// Contest : Codeforces - Codeforces Round #495 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1004/F
// Memory Limit : 512 MB
// Time Limit : 4000 ms
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
#define INF (1ll<<58)
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
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef std::pair<ll,ll> pll;
typedef std::string str;
//---------END-------//
 
#define all(x) begin(x), end(x)
#define x first
#define y second
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const int MAX_N = 2e5 + 10;
 
struct Event {
	int x, type, i;
} events[3 * MAX_N];
 
bool operator<(const Event &a, const Event &b) {
	if (a.x < b.x)
		return true;
	if (a.x > b.x)
		return false;
	if (a.type < b.type)
		return true;
	return false;
}
 
int p[MAX_N], s[MAX_N], b[MAX_N];
int inc[MAX_N], pref[MAX_N], res[MAX_N];
 
ordered_set<pair<int, int>> fenw[MAX_N];
map<int, int> values;
 
void addTo(int x, int y, int i) {
	for (; x < MAX_N; x = (x | (x + 1)))
		fenw[x].insert({y, i});
}
 
void removeFrom(int x, int y, int i) {
	for (; x < MAX_N; x = (x | (x + 1)))
		fenw[x].erase({y, i});
}
 
int get(int x, int y) {
	int ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		ans += fenw[x].order_of_key({y, -1});
	return ans;
}
 
int main() {
    fio;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < m; ++i)
		cin >> inc[i];
	for (int i = 0; i < m; ++i)
		cin >> pref[i];
	int eventsCnt = 0;
	for (int i = 0; i < n; ++i) {
		events[eventsCnt++] = {p[i], 0, i};
		events[eventsCnt++] = {s[i], 2, i};
	}
	for (int i = 0; i < m; ++i)
		events[eventsCnt++] = {inc[i], 1, i};
	sort(events, events + eventsCnt);
	for (int i = 0; i < m; ++i)
		values[inc[i] + pref[i]] = 0;
	for (int i = 0; i < n; ++i)
		values[p[i] + b[i]] = 0;
	int cnt = 1;
	for (auto &e : values)
		e.y = cnt++;
	for (int i = 0; i < eventsCnt; ++i) {
		Event e = events[i];
		if (e.type == 0) {
			addTo(values[p[e.i] + b[e.i]], p[e.i] - b[e.i], e.i);
		} else if (e.type == 1) {
			res[e.i] = get(values[inc[e.i] + pref[e.i]], inc[e.i] - pref[e.i] + 1);
		} else if (e.type == 2) {
			removeFrom(values[p[e.i] + b[e.i]], p[e.i] - b[e.i], e.i);
		}
	}
	for (int i = 0; i < m; ++i)
		cout << res[i] << " ";
	cout << "\n";
}