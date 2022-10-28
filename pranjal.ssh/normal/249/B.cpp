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
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

int n, t;
string s;
bool f(int mid) {
	int sc = count(all(s), 'S') + mid;
	int hc = count(all(s), 'H');
	if (sc < hc) return false;
	string temp = s;
	NFOR (i, n - 1, 0) {
		if (sc == hc) break;
		if (s[i] == 'S') s[i] = '.', --sc;
	}
	int last = -1;
	int till = -1;
	FOR (i, 0, n - 1) {
		if (s[i] == 'S') last = i;
		if (s[i] == 'H') till = i;
	}
	vi a(n+5);
	int prv = -1;
	int shops = mid;
	int ans = 0;
	last = max(last, till);
	FOR (i, 0, last) {
		++ans;
		if (s[i] == 'S') {
			++shops;
			if (shops == 0) {
				if (ans + last - i + last - prv <= t) {s=temp;return true;}
				ans += 2*(i - prv);
			}
		}
		else if (s[i] == 'H'){
			--shops;
			if (shops == -1) {
				prv = i;
			}
		}		
	}
	
	s = temp;
	return ans <= t;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> t;
	cin >> s;
	// pr(f(0));exit(0);
	int st = 0, en = n;
	while (st < en) {
		int mid = (st + en) >> 1;

		if (f(mid)) en = mid;
		else st = mid + 1;
	}
	if (not f(st)) st = -1;
	cout << st << "\n";

	return 0;
}