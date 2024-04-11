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

	int n; cin >> n;
	vi a(n);
	set<ii> s;
	map<int, set<int>> mp;
	FOR (i, 0, n - 1) {
		cin >> a[i];
	}
	
	FOR (i, 0, n - 1) {
		int j = i;
		while (j < n and a[i] == a[j]) ++j;
		s.insert(ii(i, j-i));
		mp[j-i].insert(i);
		i = j-1;
	}
	s.insert(ii(-1, INT_MIN));
	s.insert(ii(n+1, INT_MAX));
	int ans = 0;
	while (sz(s) > 2) {
		if (mp.rbegin()->S.empty()) {
			mp.erase(--mp.end());
			continue;
		}
		int pos = *(mp.rbegin()->S.begin());
		mp.rbegin()->S.erase(pos);

		auto it = s.upper_bound(ii(pos, inf));
		int R = it->F, L = -1, cnt = it->S;
		auto temp = *it;
		--it, --it;
		L = it->F;
		if (L >= 0 and R < n and a[L] == a[R]) {
			mp[it->S].erase(it->F);
			mp[temp.S].erase(temp.F);
			mp[cnt += it->S].insert(R);
			s.erase(it);
			s.erase(temp);
			s.insert(ii(R, cnt));
		}
		s.erase(s.upper_bound(ii(pos, -inf)));
		++ans;
	}
	cout << ans << "\n";

	return 0;
}