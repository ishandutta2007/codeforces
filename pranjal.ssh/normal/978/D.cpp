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

	int n; cin >> n;
	vector<ll> A(n); FOR (i, 0, n - 1) cin >> A[i];
	int ans = inf;
	if (n <= 2) {
		cout << "0\n";
	} else {
		FOR (i, -1, 1) {
			FOR (j, -1, 1) {
				auto a = A;
				a[0] += i;
				a[1] += j;
				int req = abs(i) + abs(j);
				ll d = a[1] - a[0];
				FOR (k, 2, n - 1) {
					if (abs(a[k] - a[k - 1] - d) <= 1) {
						req += abs(a[k] - a[k - 1] - d);
						a[k] = a[k - 1] + d;
					}
					else {req = inf;break;}
				}
				ans = min(ans, req);
			}
		}
		if (ans == inf) ans = -1;
		cout << ans;
	}

	return 0;
}