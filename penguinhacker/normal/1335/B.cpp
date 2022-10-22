#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, a, b;

void solve() {
	cin >> n >> a >> b;
	string ans="", temp;
	for (int i=0; i<b; ++i)
		temp+=('a'+i);
	for (int i=b; i<a; ++i)
		temp+='a';
	while (n) {
		if (n>=a) {
			ans+=temp;
			n-=a;
		}
		else {
			for (int i=0; i<n; ++i)
				ans+=temp[i];
			break;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}