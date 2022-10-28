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
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}

const int N = 1e6;
int sv[N+1];
vi p;

ll tot(ll n) {
	if (n <= N) {
		ll ans = n;
		ll x = n;
		while (x > 1) {
			ll t = sv[x];
			while (x % t == 0) x /= t;
			ans /= t;
			ans *= (t - 1);
		}
		return ans;
	}
	ll ans = n;
	for (int it : p) {
		if (it > n) break;
		if (n % it)continue;
		while (n % it == 0) {
			n /= it;
		}
		ans /= it;
		ans *= (it - 1);
	}
	if (n > 1)
	ans /= n, ans *= (n-1);
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	ll n, k; cin >> n >> k;
	FOR (i, 1, N)sv[i] = i;
	FOR (i, 2, 1000) {
		if (sv[i] == i){ 
			for (int j = i*i; j <= N; j += i)
				sv[j] = i;
		}
	}
	FOR (i, 2, N) {
		if (sv[i] == i){
			p.push_back(i);
		}
	}
	k = (k+1)/2;

	while (k--) {
		n = tot(n);
		if (n == 1) break;
	}	
	cout << n % inf << "\n";
		
	return 0;
}