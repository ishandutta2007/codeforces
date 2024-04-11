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

const int N = 4e5+10;
ll wt[N];
int P[20][N];
ll sum[20][N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int Q; cin >> Q;
	ll last = 0;
	int cnt = 1;
	while (Q--) {
		ll t, p, q; cin >> t >> p >> q;
		if (t == 1) {
			ll R = p ^ last, W = q ^ last;
			// pr(R, W);
			++cnt;
			wt[cnt] = W;
			if (wt[R] >= W) {
				P[0][cnt] = R;
			} else {
				// if (cnt == 5) pr(R);
				NFOR (i, 19, 0) {
					if (P[i][R] and wt[P[i][R]] < W) R = P[i][R];
				}
				if (P[0][R] and wt[P[0][R]] >= W) P[0][cnt] = P[0][R];
			}
			sum[0][cnt] = W + wt[P[0][cnt]];
			FOR (i, 1, 19) {
				P[i][cnt] = P[i-1][P[i-1][cnt]];
				sum[i][cnt] = sum[i-1][cnt] + sum[i-1][P[i-1][cnt]] - wt[P[i-1][cnt]];
			}
			// pr(cnt, P[0][cnt]);

		} else {
			ll R = p ^ last, X = q ^ last;
			// pr(R, X);
			if (wt[R] > X) {
				last = 0;
				cout << "0\n";
			} else {
				int len = 1;
				ll now = wt[R];
				int id = R;
				NFOR (i, 19, 0) {
					if (P[i][id] and now+sum[i][id]-wt[id] <= X) {
						now += sum[i][id]-wt[id];
						len += (1 << i);
						id = P[i][id];
					}
				}
				last = len;
				cout << len << "\n";
			}
		}
	}

	return 0;
}