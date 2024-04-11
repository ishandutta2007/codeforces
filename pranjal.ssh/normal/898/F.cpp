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

bool isPrime(int x) {
	for (int i = 2; i*i <= x; i++) if (x % i == 0) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	string s; cin >> s;
	int n = s.length();
	vector<int> primes;
	for (int i = inf; sz(primes) < 10; --i) {
		if (isPrime(i)) primes.push_back(i);
	}

	vector<vi> p(10, vi(n));//, inv(10, vi(n));
	vector<vi> sum(10, vi(n));
	FOR (i, 0, 9) {
		int pr = primes[i];
		p[i][0] = 1, p[i][1] = 10;// inv[i][1] = 1;
		FOR (j, 2, n-1) {
			p[i][j] = (p[i][j-1]*10LL)%pr;
			// inv[i][j] = pr - (pr/j*1LL*inv[i][j%pr]) % pr;
		}
		sum[i][0]=s[0]-'0';
		FOR (j, 1, n-1) {
			sum[i][j] = (sum[i][j-1]*10LL+(s[j]-'0'))%pr;
		}
	}

	auto get = [&] (int l, int r){
		vector<int> ans(10);
		FOR (i, 0, 9) {
			int pr = primes[i];
			if (l == 0) {
				ans[i] = sum[i][r];
			} else {
				ans[i] = (sum[i][r] + (pr- (sum[i][l-1]*1LL*p[i][r-l+1])%pr))%pr;
			}
		}
		return ans;
	};

	auto add = [&] (vi x, const vi&y) -> vi {
		FOR (i, 0, 9) {
			x[i] = (x[i]+y[i])%primes[i];
		}
		return x;
	};

	FOR (i, 0, n - 1) {
		int len = n - i;
		for (int x : {len, len-1}) if (x > 0) {
			int y = n - len - x;
			if (y > 0 and y <= x and (s[n-len] != '0' or len==1)) {
				if ((s[0] != '0' or x==1) and (s[x] != '0' or y==1) and add(get(0, x-1),get(x, x+y-1)) == get(x+y, n-1)) {
					return cout << s.substr(0, x) << "+" << s.substr(x, y) << "=" << s.substr(x+y), 0;
				}
				swap(x, y);
				if (s[x] != '0' and add(get(0, x-1),get(x, x+y-1)) == get(x+y, n-1)) {
					return cout << s.substr(0, x) << "+" << s.substr(x, y) << "=" << s.substr(x+y), 0;
				}
				swap(x, y);
			}
		}
	}

	return 0;
}