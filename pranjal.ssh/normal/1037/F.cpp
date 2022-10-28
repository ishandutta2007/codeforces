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

	int n, k; cin >> n >> k;
	vi a(n);
	FOR (i, 0, n - 1) cin >> a[i];
	vi b;
	b.push_back(k);
	while (b.back()+k-1 <= n) b.push_back(b.back()+k-1);
	stack<int> st;
	vi nxt(n, n);
	NFOR (i, n-1, 0) {
		while (!st.empty() and a[st.top()] <= a[i]) st.pop();
		if (!st.empty()) nxt[i] = st.top();
		st.push(i);
	}
	vi prv(n, -1); while (!st.empty()) st.pop();
	FOR (i, 0, n - 1) {
		while (!st.empty() and a[st.top()] < a[i]) st.pop();
		if (!st.empty()) prv[i] = st.top();
		st.push(i);	
	}
	int ans = 0;
	FOR (i, 0, n - 1) {
		int l = prv[i]+1, r = nxt[i]-1;
		ll count = 0;
		if (i-l < r-i) {
			NFOR (it, i, l) {
				int L = i-it+1, R = r-i;
				count += upper_bound(all(b), L+R) - lower_bound(all(b), L);
			}
		} else {
			FOR (it, i, r) {
				int R = it-i+1, L = i-l;
				count += upper_bound(all(b), L+R) - lower_bound(all(b), R);
			}
		}
		count %= inf;
		ans += (a[i] * 1LL * count) % inf;
		if (ans >= inf) ans -= inf;
	}
	cout << ans;



	return 0;
}