#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=998244353;

ll bp(ll b, ll p=M-2) {
	ll r=1;
	for (; p; p/=2, b=b*b%M)
		if (p%2)
			r=r*b%M;
	return r;
}

const ll two=bp(2), three=bp(3);

ll geo(ll a, ll r, ll n) {
	return a*(bp(r, n)-1)%M*bp(r-1)%M;
}

ll f(int n) {
	return (bp(2, 2*n)*geo(two, two, n)%M-bp(3, n)*geo(2*three%M, 2*three%M, n)%M+M)%M;
}

ll get_num(string s) {
	ll r=0;
	for (char c : s)
		r=(2*r+c-'0')%M;
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string num;
	cin >> num;
	int n=num.size();
	if (n<=2) {
		cout << 0;
		return 0;
	}
	vector<ll> p(n, 1), suf(n);
	for (int i=1; i<n; ++i)
		p[i]=p[i-1]*2%M;
	for (int i=n-1; ~i; --i)
		suf[i]=((i+1<n?suf[i+1]:0)+(num[i]=='1'?p[n-1-i]:0))%M;
	ll ans=0, pref=0;
	for (int i=0; i<n-2; ++i) {
		ans=(ans+6*pref%M*bp(2, n-i-1)%M*f(n-i-1))%M;
		if (num[i]=='1')
			ans=(ans+3*f(n-i-1)%M*(suf[i+1]+1))%M;
		pref=(2*pref+num[i]-'0')%M;
	}
	vector<ll> dp1(2); // stores : not tight, tight
	vector<vector<ll>> dp2(2, vector<ll>(2)); // bad/good || not tight tight
	for (int i=0; i<n; ++i) {
		vector<ll> ndp1(2);
		vector<vector<ll>> ndp2(2, vector<ll>(2));
		ndp1[0]=(2*dp1[0]+(num[i]=='1'?3:0))%M;
		ndp1[1]=(4*dp1[1]+(num[i]=='1'?2*dp1[0]:0))%M;
		ndp2[0][0]=(3*dp2[0][0]+(num[i]=='1'?4*dp1[0]:0))%M;
		ndp2[0][1]=(6*dp2[0][1]+(num[i]=='1'?3*dp2[0][0]:0)+4*dp1[1])%M;
		ndp2[1][0]=(4*dp2[1][0]+dp2[0][0])%M;
		ndp2[1][1]=(8*dp2[1][1]+(num[i]=='1'?4*dp2[1][0]+dp2[0][0]:0)+2*dp2[0][1])%M;
		swap(dp1, ndp1);
		swap(dp2, ndp2);
	}
	ans=(ans+dp2[1][0]+dp2[1][1])%M;
	cout << ans;
	return 0;
}