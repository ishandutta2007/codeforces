#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define SP << " "
#define EL << "\n"
#define sqr(x) ((x)*(x))
//mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;

template <class T1,class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	return out << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator << (ostream& out, vector<T> v) {
	out << "[";
	for (auto it = v.begin(); it < v.end(); it++) {
		if (it != v.begin())
			out << ",";
		out << *it;
	}
	out << "]";
	return out;
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();

/******************************************/

struct prime_sieve{
	vector<int> primes;
	vector<bool> isComposite;
	
	int checkPrime(int x) {
		vector<int>::iterator it = lower_bound(primes.begin(),primes.end(),x);
		if (it != primes.end() && *it == x)
			return it - primes.begin() + 1;
		else
			return -1;
	}
	
	prime_sieve(int n) {
		primes.clear();
		isComposite.resize(n+1);
		
		for (int i = 2; i <= n; i++) {
			if (!isComposite[i])
				primes.push_back(i);
			for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
				isComposite[i*primes[j]] = 1;
				if (i % primes[j] == 0)
					break;
			}
		}		
	}
};

map<int,int> m;
bool isRemoved[400005];
vector<int> ans;

int main() {
	int n;
	cin >> n;	
	
	for (int i = 0; i < 2*n; i++) {
		int x;
		cin >> x;
		m[x]++;
	}
	
	prime_sieve p(2750131);
	
	for (map<int,int>::reverse_iterator it = m.rbegin(); it != m.rend(); it++) {
		int loc = p.checkPrime(it->first);
		while (it->second > 0) {
			if (loc != -1) {
				m[loc]--;
				ans.push_back(loc);
			} else {
				int corr;
				for (auto i : p.primes) {
					if (it->first % i == 0) {
						corr = it->first / i;
						break;
					}
				}
				m[corr]--;
				ans.push_back(it->first);
			}
			it->second--;
		}
	}
	
	for (auto i : ans)
		cout << i SP;
	
	return 0;
}