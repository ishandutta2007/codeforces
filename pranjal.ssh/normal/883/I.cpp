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

const int N = 3e5;

int bt[N + 1];
int n, k;
void upd(int i) {
	while (i <= n) bt[i]++, i += i&-i;
}
int qry(int i) {
	int ans = 0;
	while (i > 0) ans += bt[i], i -= i&-i;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	vi a(n+1);
	FOR (i, 1, n) cin >> a[i];
	sort(a.begin()+1, a.end());
	int st = 0, en = 1e9;
	while (st < en) {
		int mid = (st + en) >> 1;
		
		FOR (i, 1, n) bt[i] = 0;
		FOR (i, k, n) {
			if (a[i] - a[1] <= mid) {
				upd(i); continue;
			}
			int u = lower_bound(a.begin()+1, a.begin()+i, a[i] - mid) - a.begin() - 1;
			int v = i - k;
			if (u <= v && qry(v) - qry(u-1))
				upd(i);
		}
		
		if (qry(n) - qry(n-1)) en = mid;
		else st = mid + 1;
	}
	cout << st;
	
	
	return 0;
}