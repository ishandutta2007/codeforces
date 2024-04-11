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

	string s, t; cin >> s >> t;
	sort(all(s)), sort(all(t)), reverse(all(t));
	int n = sz(s);
	s = s.substr(0, (n+1)/2);
	t = t.substr(0, n/2);
	reverse(all(t));

	deque<char> S, T;
	for (char ch: s) S.push_back(ch);
	for (char ch: t) T.push_back(ch);
	vector<char> ans(n);
	int lp = 0, rp = n-1;
	FOR (i, 0, n - 1) {
		if (i&1) {
			if (not S.empty() and S.front() >= T.back()) {
				ans[rp--] = T.front(); T.pop_front();
			}
			else {
				ans[lp++] = T.back(); T.pop_back();
			}
		}
		else {
			if (not T.empty() and T.back() <= S.front()) {
				ans[rp--] = S.back(); S.pop_back();
			}
			else {
				ans[lp++] = S.front(); S.pop_front();
			}
		}
	}
	
	cout << string(all(ans)) << "\n";

	return 0;
}