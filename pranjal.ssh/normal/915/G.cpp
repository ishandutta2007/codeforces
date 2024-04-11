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

const int N = 2e6;
int sv[N+1], mu[N+1];
int pw[N+1];
int f[N+1];

int expo(int n, int p, int mod = inf) {
    int ans = 1;
    while (p) {
        if (p & 1) {
            ans = (ans * 1LL * n) % mod;
        }
        n = (n * 1LL * n) % mod;
        p >>= 1;
    }
    return ans;
}
void ok(int &x) {
	if (x >= inf) x -= inf;
	if (x < 0) x += inf;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;

	FOR (i, 1, k) sv[i] = i;
	FOR (i, 2, 2000) if (sv[i] == i) for (int j = i * i; j <= k; j += i) sv[j] = i;

	mu[1] = 1;
	FOR (i, 2, k) {
		int x = sv[i];
		int g = (i / x) % x != 0;
		mu[i] = mu[i / x] * -g;
	}


	FOR (i, 1, k) {
		if (sv[i] == i) {
			pw[i] = expo(i, n);
		} else {
			pw[i] = (pw[sv[i]] * 1LL * pw[i/sv[i]]) % inf;
		}
	}


	int ans = 0;
	FOR (i, 1, k) {
		if (mu[i]) {
			for (int j = i; j <= k; j += i) {
				ok(f[j] -= pw[(j-1)/i]*mu[i]);
				ok(f[j] += pw[j/i]*mu[i]);
			}
		}
		ok(f[i] += f[i - 1]);
		ok(ans += (f[i]^i));
	}
	cout << ans << "\n";



	return 0;
}