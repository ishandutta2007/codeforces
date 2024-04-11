#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll;typedef pair <int, int> ii;typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ", ";dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T> void prc(T a, T b) {cerr << "[";for (T i = a; i != b; ++i) {if (i != a) cerr << ", ";cerr << *i;}cerr << "]\n";}

const int N = 2020;
ll F[N][N];
ll G[N][N];
string s;
ll g(int n, int k);
ll f(int n, int k) {
	if (k < 0) return 0;
	if (n == 0) return k == 0;
	ll& ans = F[n][k];
	if (ans != -1) return ans;
	ans = 0;
	int ch = s[sz(s) - n] - 'a';
	ans = ch*f(n-1, k) + (25-ch)*f(n-1, k-n) + g(n-1, k) + (k==0);
	int nk = k;
	for (int i = 1; i <= n - 1; ++i) {
		int ch = s[sz(s) - n + i] - 'a';
		nk = k - (i+1)*(n-i);
		if (nk < 0) {
			for (int i = n - 1; i >= 1; --i) {
				int ch = s[sz(s) - n + i] - 'a';
				nk = k - (i+1)*(n-i);
				if (nk < 0) break;
				ans += (25-ch)*f(n-i-1, nk);
				ans %= inf;
			}
			break;
		}
		ans += (25-ch)*f(n-i-1, nk);
		ans %= inf;
	}
	ans %= inf;
	return ans;
}

ll g(int n, int k) {	//chota
	if (k < 0) return 0;
	if (n == 0) return 0;
	ll& ans = G[n][k];
	if (ans != -1) return ans;
	int ch = s[sz(s) - n] - 'a';
	ans = ch*f(n-1, k) + g(n-1, k);
	ans %= inf;
	return ans;
}

int main() 
{
   ios::sync_with_stdio(0); cin.tie(0);

   int n, k; cin >> n >> k;
   memset(F, -1, sizeof F);
   memset(G, -1, sizeof G);
   cin >> s;
   cout << f(n, k) << "\n";
   return 0;
}