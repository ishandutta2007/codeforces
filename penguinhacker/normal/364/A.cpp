#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int a, c[40001];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> s;
	for (int i=0; i<s.size(); ++i) {
		int cur=0;
		for (int j=i; j<s.size(); ++j) {
			cur+=s[j]-'0';
			++c[cur];
		}
	}
	if (a==0) {
		//cout << (ll)c[0]*c[0];
		ll ans=(ll)c[0]*c[0];
		for (int i=1; i<=40000; ++i)
			ans+=2ll*c[0]*c[i];
		cout << ans;
		return 0;
	}
	ll ans=0;
	for (int i=1; i<=40000; ++i) {
		if (!c[i]||a%i||a/i>40000)
			continue;
		ans+=(ll)c[i]*c[a/i];
	}
	cout << ans;
	return 0;
}