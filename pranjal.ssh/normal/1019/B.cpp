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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}

map<int, int> M;
int n;
int get(int x) {
	if (M.count(x)) return M[x];
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &M[x]);
	return M[x];
}

inline int sum(int l, int r) {
	return get(r % n + 1) - get(l);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);


	scanf("%d", &n);
	if ((n / 2) & 1) {
		printf("! -1\n");
		fflush(stdout);
		return 0;
	}

	int m = n / 2;
	if (sum(1, m) % 2 != 0) {
		printf("! -1\n");
		fflush(stdout);
		return 0;
	}

	int l = 1, r = m;
	int ans = -1;
	int L = sum(l, l+m-1), R = sum(r, r+m-1);
	if (L == 0) {
		ans = l;
	} else if (R == 0) {
		ans = r;
	} else if (L * 1LL * R >= 0) {
		printf("! -1\n");
		fflush(stdout);
		return 0;	
	} else {
		while (l < r) {
			int mid = (l + r) / 2;
			int x = sum(mid, mid + m - 1);
			if (x == 0) {
				l = mid;
				break;
			}
			if (x * 1LL * L > 0) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		ans = l;
	}
	printf("! %d\n", ans);
	fflush(stdout);

	return 0;
}