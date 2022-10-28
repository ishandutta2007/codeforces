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


ll off[70];

inline int getLevel(ll x) {
	return 63 - __builtin_clzll(x);
}

void get(ll x) {
	int l = getLevel(x);
	x += off[l];
	if (x > (1LL << (l + 1)) - 1) x -= (1LL << l);
	while (l >= 0) {
		ll rv = x - off[l];
		if (rv < (1LL << l)) rv += (1LL << l);
		printf("%lld ", rv);
		x /= 2;
		--l;
	}
}

int main()
{

	int q; scanf("%d", &q);
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			ll x, k; scanf("%lld %lld", &x, &k);
			int l = getLevel(x);
			k %= (1LL << l);
			if (k < 0) k += (1LL << l);
			off[l] = (off[l] + k) % (1LL << l);
		} else if (t == 2) {
			ll x, k; scanf("%lld %lld", &x, &k);
			int l = getLevel(x);
			k %= (1LL << l);
			if (k < 0) k += (1LL << l);
			FOR (it, l, 61) {
				off[it] = (off[it] + k);
				if (off[it] >= (1LL << it)) off[it] -= (1LL << it);
				k *= 2;
			}
		} else {
			ll x; scanf("%lld", &x);
			get(x);
			putchar('\n');
		}
	}

	return 0;
}