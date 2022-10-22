#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=998244353;
int n, fr[mxN+1], d[mxN+1];
bool bad[mxN+1];
ll ans;

ll bp(ll b, ll p) {
	ll r=1;
	for (; p; p/=2, b=b*b%M)
		if (p%2)
			r=r*b%M;
	return r;
}

ll solve(int x) {
	ll tot=0, s1=0, s2=0;
	for (int i=x; i<=mxN; i+=x) {
		tot+=fr[i];
		s1=(s1+(ll)i*i%M*fr[i])%M;
		s2=(s2+(ll)i*fr[i])%M;
	}
	if (tot<2)
		return 0;
	s2=(s2*s2-s1+M)%M*(M+1)/2%M;
	return (s1*((tot-1)%M)+s2*(tot%M))%M*bp(2, tot-2)%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		int a;
		cin >> a;
		cin >> fr[a];
	}
	for (int i=2; i<=mxN; ++i) {
		if (!d[i]) {
			for (int j=i; j<=mxN; j+=i)
				++d[j];
			for (ll j=(ll)i*i; j<=mxN; j+=(ll)i*i)
				bad[j]=1;
		}
	}
	for (int i=1; i<=mxN; ++i)
		if (!bad[i])
			ans=(ans+solve(i)*(d[i]%2?-1:1)+M)%M;
	cout << ans;
	return 0;
}