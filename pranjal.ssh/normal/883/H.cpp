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
	string s; cin >> s;
	vi f(128);
	for (char ch : s) {
		f[ch]++;
	}
	vi odd;
	FOR (i, 0, 127) if (f[i]&1) odd.push_back(i), --f[i];
	vector<deque<int>> ans;

	FOR (it, 1, n) if (n % it == 0) {
		int len = n / it, num = it;
		if (len & 1) {
			if (num >= sz(odd) && (num - sz(odd)) % 2 == 0) {
				ans.resize(num);
				FOR (i, 0, num - 1) {
					if (!odd.empty()) {
						ans[i].push_back(odd.back()); odd.pop_back();
					} else {
						int ptr = 0;
						FOR (j, i, num - 1) {
							while (f[ptr] == 0) ++ptr;
							f[ptr]--;
							ans[j].push_back(ptr);
						}
						break;
					}
				}
				int ctr = 0, ptr = -1;
				len ^= 1;
				FOR (i, 0, 127) {
					FOR (j, 1, f[i]/2) {
						if (ctr % len == 0) ++ptr;
						ans[ptr].push_back(i), ans[ptr].push_front(i);
						ctr += 2;
					}
				}
				break;
			}
		} else {
			if (sz(odd) == 0) {
				int ctr = 0, ptr = -1;ans.resize(num);
				FOR (i, 0, 127) {
					FOR (j, 1, f[i]/2) {
						if (ctr % len == 0) ++ptr;
						ans[ptr].push_back(i), ans[ptr].push_front(i), ctr += 2;
					}
				}
				break;
			}
		}
	}

	cout << sz(ans) << "\n";
	for (auto &it : ans) {
		for (int x : it) {
			cout << (char)x;
		}
		cout << " ";
	}

	return 0;
}