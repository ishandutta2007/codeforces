#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int a[1<<12];
int bc[1<<12][1<<12];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int w, n, m; cin >> w >> n >> m;
	
	FOR (i, 0, n - 1) {
		int x; cin >> x; a[x]++;
	}
	FOR (i, 0, (1 << w) - 1) {
		FOR (j, 0, (1 << w) - 1) {
			bc[j][i^(i&j)]+= a[i];
		}
	}
	char mp[128];
	mp['A'] = 0, mp['O'] = 1, mp['X'] = 2;
	mp['a'] = 3, mp['o'] = 4, mp['x'] = 5;
	int SAB = (1<<w)-1;
	while (m--) {
		string s; cin >> s; reverse(all(s));
		vi b(6);
		FOR (i, 0, w - 1) {
			b[mp[s[i]]] |= (1 << i);
		}
		int ans = 0;
		FOR (i, 0, (1 << w) - 1) {
			int ti = SAB^i;
			int o = 0, z = 0;

			z |= (i & b[0]);

			if (i & b[1]) continue;
			z |= b[1];

			z |= ti & b[2];
			o |= i & b[2];

			if (ti & b[3]) continue;
			o |= b[3];

			o |= (ti & b[4]);

			z |= i & b[5];
			o |= ti & b[5];

			if (o & z) continue;
			ans += a[i] * bc[SAB^o^z][o];
		}
		cout << ans << "\n";
	}


	
	return 0;
}