#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MX=5e6;
int n, cnt[MX+1];
ll dp[MX+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		int a;
		cin >> a;
		for (int j=1; j*j<=a; ++j) {
			if (a%j)
				continue;
			++cnt[j];
			if (j*j!=a)
				++cnt[a/j];
		}
	}
	dp[1]=n;
	for (int i=1; i<=MX; ++i)
		for (int j=2*i; j<=MX; j+=i)
			dp[j]=max(dp[j], dp[i]+(ll)(j-i)*cnt[j]);
	cout << *max_element(dp, dp+MX+1);
	return 0;
}