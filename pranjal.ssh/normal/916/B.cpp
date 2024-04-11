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

	ll n; cin >> n;
	int k; cin >> k;
	int req = __builtin_popcountll(n);

	if (k < req) {
		cout << "No\n";
		return 0;
	}

	vector<int> a;
	FOR (y, -20, 60) {
		ll x = (1LL << abs(y));
		if (y >= 0) {
			ll req = n / x + __builtin_popcountll(n % x);
			if (req <= k) {
				FOR (i, 1, n/x) a.push_back(y);
				n %= x;
				NFOR (i, 60, 0) if (n >= (1LL << i)) {
					n -= (1LL << i);
					a.push_back(i);
				}		
				break;
			}
		} else {
			if (k >= n and k >= n * x) {
				a = vector<int>(n*x, y);
				break;
			}
		}
	}
	assert(sz(a) <= k);
	while (sz(a) < k) {
		int x = a.back();
		a.pop_back();
		a.push_back(x - 1);
		a.push_back(x - 1);
	}
	cout << "Yes\n";
	for (int x : a) cout << x << " ";
	

	return 0;
}