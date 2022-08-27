#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define x first
#define y second
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7, mod = 998244353;
template<typename T> inline void cmax(T &x, T y) { if(x < y) x = y; }
template<typename T> inline void cmin(T &x, T y) { if(y < x) x = y; }
using namespace std;
int n, a[N], nx[N], vis[N];
vector<int> ns; 
void Main() {
	cin >> n;
	L(i, 1, n) cin >> a[i], nx[i] = i % n + 1, vis[i] = true;
	vector<int> v;
	L(i, 1, n) if(__gcd(a[i], a[nx[i]]) == 1) v.push_back(i);
	ns.clear();
	while(!v.empty()) {
		vector< int > sv;
		int las = 0;
		for(int x : v) if(vis[x] && las != x) {
			vis[nx[x]] = false, ns.push_back(nx[x]), las = nx[x], nx[x] = nx[nx[x]];
			if(__gcd(a[x], a[nx[x]]) == 1) sv.push_back(x);
		}
		swap(v, sv);
	}
	cout << sz(ns) << " ";
	L(i, 0, sz(ns) - 1) cout << ns[i] << " ";
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}