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

const int N = 1e6;
int sv[N+1];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	FOR (i, 1, N) sv[i] = i;
	FOR (i, 2, 1000) if (sv[i] == i) for (int j = i * i; j <= N; j += i) sv[j] = i;

	int t; cin >> t; while (t--) {
		int x, p, k; cin >> x >> p >> k;
		vector<int> primes;
		while (p > 1) {
			int x = sv[p];
			primes.push_back(x);
			while (p % x == 0) p /= x;
		}

		int st = x + 1, en = 1e7;
		int no = sz(primes);
		vector<int> prod(1 << no);
		prod[0] = 1;
		FOR (i, 1, sz(prod) - 1) {
			int j = i & (i - 1);
			prod[i] = prod[j] * primes[__builtin_ctz(i ^ j)];
		}
		auto qry = [&] (int y) {
			int ans = 0;
			FOR (i, 0, sz(prod) - 1) {
				if (__builtin_popcount(i) & 1) ans -= y / prod[i];
				else ans += y / prod[i];
			}
			return ans;
		};
		int xq = qry(x);
		while (st < en) {
			int mid = (st + en) >> 1;
			int num = qry(mid) - xq;
			if (num >= k) en = mid;
			else st = mid + 1;
		}
		cout << st << "\n";
	}

	return 0;
}