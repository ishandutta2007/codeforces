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

int C[5020][5020];
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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	ll n, k; cin >> n >> k;
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	if (n < k + 10) {
		int ans = 0;

		FOR (i, 0, n) {
			C[i][0]=1;
			FOR (j, 1, i) {
				C[i][j] = C[i-1][j-1]+C[i-1][j];
				if (C[i][j] >= inf) C[i][j] -= inf;
			}
		}
		FOR (i, 1, n) {
			ans = (ans + C[n][i] * 1LL * expo(i, k)) % inf; 

		}
		cout << ans << "\n";
		return 0;
	}

	vector<int> A, B;
	A.push_back(1);
	A.reserve(k+1), B.reserve(k+1);
	FOR (i, 1, k) {
		// diff.
		B.clear();
		B.resize(sz(A));
		FOR (i, 0, sz(A)-1) {
			if (i) {
				B[i-1] = (B[i-1] + A[i]*1LL*i) % inf;
			}
			{
				B[i] = (B[i] + A[i]*1LL*(n-i)) % inf;
			}
		}
		// pr(B);
		
		if (i == k) {
			int ans = 0;
			FOR (i, 0, sz(B)-1) {
				ans = (ans + B[i]*1LL*expo(2, n-1-i)) % inf;
			}
			cout << ans << "\n";
			return 0;
		}
		// mult.
		B.push_back(B.back());
		NFOR (i, sz(B)-2, 1) B[i] = B[i-1];
		B[0] = 0;
		A.swap(B);
	}

	return 0;
}