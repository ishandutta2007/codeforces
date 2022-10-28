#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<vi> s(2);
	int k1; cin >> k1; s[0].resize(k1);
	for (int &x: s[0]) cin >> x;
	int k2; cin >> k2; s[1].resize(k2);
	for (int &x: s[1]) cin >> x;

	queue<ii> q;
	vector<vi> vis(n, vi(2));
	vector<vi> ans(n, vi(2));
	vector<vi> deg(n, vi(2));

	vis[0][0] = 1, vis[0][1] = 1, q.push(ii(0, 0)), q.push(ii(0, 1));
	ans[0][0] = 1, ans[0][1] = 0;

	while (not q.empty()) {
		ii now = q.front();
		q.pop();
		
		for (int x: s[!now.S]) {
			int at = (now.F - x + n) % n;
			if (not vis[at][!now.S]) {
				if (ans[now.F][now.S] == !now.S) {
					vis[at][!now.S] = 1;
					ans[at][!now.S] = !now.S;
					q.push(ii(at, !now.S));
				}
				else {
					if (++deg[at][!now.S] == s[!now.S].size()) {
						vis[at][!now.S] = 1;
						ans[at][!now.S] = now.S;
						q.push(ii(at, !now.S));
					}
				}
			}
		}
	}

	FOR (i, 1, n - 1) {
		cout << (vis[i][0] ? (ans[i][0] ? "Lose" : "Win") : "Loop") << " \n"[i+1 == n];
	}

	FOR (i, 1, n - 1) {
		cout << (vis[i][1] ? (ans[i][1] ? "Win" : "Lose") : "Loop") << " \n"[i+1 == n];
	}



	return 0;
}