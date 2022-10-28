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


inline int SQRT(int x) {
	int y = sqrt(x);
	if (y*y != x) ++y;
	return y;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; ll k; cin >> n >> k;
	int yo = -1;
	vi a(n); FOR(i, 0, n - 1) cin >> a[i], k += a[i], yo = max(yo, a[i]);


	int mx = SQRT(yo);

	ll ans = 1;
	NFOR (i, mx, 2) {
		ll cost = 0;
		for (int j : a) cost += i*((j+i-1)/i);
		if (cost <= k) {
			ans = i;
			break;
		}
	}

	vector<ii> cr;
	vi ptr(n);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	ll sum = 0;
	FOR (i, 0, n - 1) {
		int x = SQRT(yo);
		ptr[i] = (a[i]+x-1)/x;
		pq.push({x, i});
		sum += ptr[i];
	}
	while (!pq.empty()) {
		auto x = pq.top();
		pq.pop();
		ptr[x.S]--;
		cr.push_back(x);
		if (ptr[x.S] == 0) {
			continue;
		}
		pq.push({(a[x.S]+ptr[x.S]-1)/ptr[x.S], x.S});
	}
	vi done(n);
	
	FOR (i, 0, sz(cr) - 1) {
		int j = i;
		for (; j < sz(cr) && cr[i].F == cr[j].F; ++j) {
			if (done[cr[j].S])
				sum--;
			else
				done[cr[j].S] = 1;
		}		
		ll nxt = j < sz(cr) ? cr[j].F-1 : 1e15;
		if (cr[i].F <= k/sum) {
			ans = max(ans, min(k/sum, nxt));
		}
		i = j-1;
	}


	cout << ans << "\n";

	return 0;
}