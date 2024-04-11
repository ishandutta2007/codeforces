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

vi A;
const int N = 1e5;
vector<pair<ll, int>> brute(int l, int r) {
	int no = r-l+1;
	vector<pair<ll, int>> ans;
	if (r < l) {ans.push_back({1LL, 0});return ans;}
	FOR (i, 0, (1 << no) - 1) {
		ll now = 1;
		FOR (j, 0, no - 1) if (i >> j & 1) {
			now *= A[j+l];
			if (now > N) break;
		}
		if (now <= N) {
			ans.push_back({now, i});
		}
	}
	return ans;
}

bool solve(int a, int b, int h, int w, int n) {
	if (n == 0) return a >= h and b >= w;
	auto a1 = brute(0, n/2), a2 = brute(n/2 + 1, n-1);
	// pr(a1,a2);
	sort(all(a2));
	for (auto &it: a1) {
		auto itt = upper_bound(all(a2), pair<ll, int>((h+a*it.F-1)/(a*it.F), -1));
		if (itt == a2.end()) continue;
		ll s = b;
		FOR (i, 0, n - 1) {
			if (i <= n/2 and (it.S >> i & 1)) continue;
			if (i > n/2 and (itt->S >> (i-n/2-1) & 1)) continue;
			s *= A[i];
			if (s >= w) break;
		}

		if (s >= w) return true;
	}
	return false;
}
int solve(int a, int b, int h, int w) {
	int n = sz(A);
	int st = 0, en = n;
	while (st < en) {
		int mid = ((st + en) >> 1);
		if (solve(a,b,h,w,mid))
			en = mid;
		else
			st = mid + 1;
	}
	return solve(a,b,h,w,st) ? st : inf;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int a, b, h, w, n; cin >> a >> b >> h >> w >> n;
	A = vi(n);
	FOR (i, 0, n - 1) cin >> A[i];
	sort(all(A)); reverse(all(A));
	n = min(n, 34); A.resize(n);
	// pr(A);
	
	int ans = min(solve(h, w, a, b), solve(h, w, b, a));
	if (ans == inf) ans = -1;
	cout << ans << "\n";

	return 0;
}