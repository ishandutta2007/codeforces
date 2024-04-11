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

	int n, s1, s2; cin >> n >> s1 >> s2;
	vi x(n); FOR (i, 0, n - 1) cin >> x[i];

	auto can = [&](int k) {
		set<int> s;
		int pos = s2;
		s.insert(s1);
		for (int i : x) {
			while (!s.empty() and abs(*s.begin() - i) > k) s.erase(s.begin());
			while (!s.empty() and abs(*s.rbegin() - i) > k) s.erase(--s.end());
			if (abs(pos - i) <= k) {
				s.insert(pos);
			}
			if (s.empty()) return false;
			pos = i;
		}
		return !s.empty();
	};

	int st = abs(s1 - s2), en = 1e9;
	while (st < en) {
		int mid = (st + en) >> 1;
		if (can(mid)) {
			en = mid;
		} else{
			st = mid + 1;	
		}
	}
	cout << st << "\n";

	return 0;
}