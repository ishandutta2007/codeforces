//      hello world


//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>

#define oo 			0xBADC0DE
#define s(n)			scanf("%d",&n)
#define sl(n) 			scanf("%lld",&n)
#define sf(n) 			scanf("%lf",&n)
#define fill(a,v) 		memset(a, v, sizeof a)
#define ull 			unsigned long long
#define ll 				long long
#define bitcount 		__builtin_popcount
#define all(x) 			x.begin(), x.end()
#define pb( z ) 		push_back( z )
#define gcd				__gcd

#define FOR(i,n) for (int i=0; i < (n); i++)

using namespace std;

const int mxn = 100000;
bool sv[mxn];
int mnprime[mxn];
vector<int> primes;

void prec() {
	primes.clear(); fill(sv, 0);
	for (int i=2; i < mxn; i++)
		mnprime[i] = (int)2e9;
	for (int i=2; i < mxn; i++)
	if (!sv[i]) {
		primes.pb(i);
		mnprime[i] = min(mnprime[i], i);
		for (int j=2*i; j < mxn; j += i) {
			sv[j] = 1;
			mnprime[j] = min(mnprime[j], i);
		}
	}
}

bool isPrime(int x) {
	for (int i=2; i*i <= x; i++)
	if (x%i == 0)
		return 0;
	return 1;
}

ll go(int primepos, ll prod, int n, int parity, const int k) {
	//cout << primepos << " " << n << " and " << prod << " with " << (parity ? '+' : '-') << n/prod <<  endl;
	ll ret = 0;
	if (parity) {
		ret += n/prod;
	} else {
		ret -= n/prod;
	}
	ll nprod = prod*primes[primepos];
	if (primes[primepos] >= k || nprod > n) return ret;
	return go(primepos+1, prod, n, parity, k) + go(primepos+1, nprod, n, parity ^ 1, k);
}

int solve(int n, int k) {
	if (k*(ll)k > n)
		return k <= n ? 1 : 0;
	
	int N = n/k;
	
	ll v = go(0, 1, N, 1, k);
	//cout << 1 << " to " << N << " numbers not divisible by primes < " << k << " = " << v << endl;
	return v;
}

void solve(int a, int b, int k) {
	if (!isPrime(k)) {
		cout << 0 << endl;
		return;
	}
	prec();
	cout << solve(b, k) - solve(a-1, k) << endl;
}
int main(int argc, char** argv) {
	int a, b, k;
	while(cin>>a>>b>>k) {
		solve(a, b, k);
	}
	return 0;
}