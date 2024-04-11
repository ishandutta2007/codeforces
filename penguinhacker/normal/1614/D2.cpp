#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MX=2e7;
int n, cnt[MX+1], p[MX/5], pp;
ll dp[MX+1];
bool b[MX+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=2; i<=MX; ++i) {
		if (b[i])
			continue;
		p[pp++]=i;
		if ((ll)i*i<=MX)
			for (int j=i*i; j<=MX; j+=i)
				b[j]=1;
	}
	cin >> n;
	for (int i=0; i<n; ++i) {
		int a;
		cin >> a;
		++cnt[a];
	}
	for (int i=0; i<pp; ++i)
		for (int j=MX/p[i]; j; --j)
			cnt[j]+=cnt[j*p[i]];
	for (int i=MX; i; --i)
		if (cnt[i]) {
			dp[i]=(ll)i*cnt[i];
			for (int j=2*i; j<=MX; j+=i)
				if (dp[j])
					dp[i]=max(dp[i], dp[j]+(ll)i*(cnt[i]-cnt[j]));
		}
	cout << dp[1];
	return 0;
}