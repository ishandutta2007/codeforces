#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	ll n, q; cin >> n >> q;
	vector<ll> Q(q); FOR (i, 0, q - 1) cin >> Q[i], --Q[i];
	vector<ll> ans(q);
	bool st = 0;
	ll off = 1;
	int done = 0;
	while (done < q) {
		FOR (i, 0, q - 1) {
			if ((Q[i] & 1) == st and ans[i] == 0) {
				ans[i] = off + (Q[i] / 2);
				++done;
			} else {
				Q[i] >>= 1;
			}
		}
		if (n & 1) {
			if (st) off += n/2, ++n;
			else off += n/2 + 1;
			st ^= 1;
		} else {
			off += n/2;
		}
		n >>= 1;
	}
	FOR (i, 0, q - 1) cout << ans[i] << "\n";

	return 0;
}