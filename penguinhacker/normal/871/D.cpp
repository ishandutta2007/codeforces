#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// #warning change
const int mxN=1e7;
int n, sp[mxN+1], pref[mxN+1], tot[mxN+1]; // smallest prime and totient function
vector<int> primes;
ll ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if (n<=3) {
		cout << 0;
		return 0;
	}
	tot[1]=1;
	for (int i=2; i<=n; ++i) {
		if (!sp[i]) {
			sp[i]=i;
			tot[i]=i-1;
			primes.push_back(i);
		}
		for (int j : primes) {
			if (i*j>n)
				break;
			sp[i*j]=j;
			if (i%j==0) {
				tot[i*j]=tot[i]*j;
				break;
			}
			tot[i*j]=tot[i]*(j-1);
		}
		++pref[sp[i]];
		ans-=i-1-tot[i];
	}
	for (int i=3; i<=n; ++i)
		pref[i]+=pref[i-1];
	for (int i=2; i<=n; ++i)
		ans+=pref[n/sp[i]];
	for (int i : primes) {
		if (2*i>n)
			break;
		int x=n/i;
		if (x>=i)
			continue;
		ans+=3ll*(pref[i]-pref[i-1])*(pref[i-1]-pref[x]);
	}
	for (int i=2; i<=n; ++i)
		if (n/sp[i]>=sp[i])
			--ans;
	cout << ans;
	return 0;
}