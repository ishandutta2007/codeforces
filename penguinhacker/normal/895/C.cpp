#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int mxN=100001, MOD=1e9+7, P=19;

int binPow(ll b, int pow=MOD-2) {
	ll res=1;
	while(pow>0) {
		if (pow&1) res=res*b%MOD;
		b=b*b%MOD;
		pow>>=1;
	}
	return res;
}

int n, numMask[71], cnt[71];
ll f[mxN], iF[mxN];
vector<int> prime;
vector<ll> dp, dpl;
int C(int a, int b) {return f[a]*iF[b]%MOD*iF[a-b]%MOD;}

void init() {
	for (int i=2; i<=70; ++i) {
		bool b=1;
		for (int j: prime) if (i%j==0) {b=0; break;}
		if (b) prime.push_back(i);
	}
	assert(prime.size()==P);
	f[0]=iF[0]=1;
	for (int i=1; i<mxN; ++i) {
		f[i]=f[i-1]*i%MOD;
		iF[i]=binPow(f[i]);
	}
	for (int i=1; i<=70; ++i) {
		int x=i;
		for (int j=0; j<P; ++j) while(x%prime[j]==0) {
			x/=prime[j];
			numMask[i]^=1<<j;
		}
	}
	dp.assign(1<<P, 0);
	dp[0]=1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	init();
	cin >> n;
	for (int i=0, a; i<n; ++i) cin >> a, ++cnt[a];
	for (int i=1; i<=70; ++i) {
		if (cnt[i]==0) continue;
		dpl=dp;
		ll sumEven=0, sumOdd=0;
		for (int j=1; j<=cnt[i]; j+=2) sumOdd+=C(cnt[i], j);
		for (int j=0; j<=cnt[i]; j+=2) sumEven+=C(cnt[i], j);
		sumEven%=MOD, sumOdd%=MOD;
		for (int mask=0; mask<(1<<P); ++mask)
			dp[mask]=(sumEven*dpl[mask]+sumOdd*dpl[mask^numMask[i]])%MOD;
	}
	cout << dp[0]-1;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/