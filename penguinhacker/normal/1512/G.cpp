#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MX=1e7, INF=1e9;

vector<int> generatePrimes(const int MXPRIME) { //nloglogn where n is MXPRIME
	vector<bool> isPrime(MXPRIME+1, 1);
	vector<int> primes;
	for (int i=2; i<=MXPRIME; ++i) {
		if (!isPrime[i]) {
			continue;
		}
		primes.push_back(i);
		for (ll j=(ll)i*i; j<=MXPRIME; j+=i) {
			isPrime[j]=0;
		}
	}
	return primes;
}
vector<int> p=generatePrimes(MX);

int ans[MX+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(ans, 0x3f, sizeof(ans));
	ans[1]=1;
	vector<ar<int, 3>> upd;
	upd.reserve(3*MX);
	for (int i : p) {
		int top=MX/i*i;
		for (ll j=i, c=i+1; c<=MX; j*=i, c+=j)
			for (int k=MX/c; k; --k)
				if (ans[k]<INF)
					upd.push_back({k*(int)c, k, (int)j});
		if (i>2)
			sort(upd.rbegin(), upd.rend());
		for (ar<int, 3> x : upd)
			ans[x[0]]=min(ans[x[0]], ans[x[1]]*x[2]);
		upd.clear();
	}
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << (ans[n]>INF?-1:ans[n]) << "\n";
	}
	return 0;
}