#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, m;
		cin >> a >> b >> c >> m;
		int mx = a + b + c - 3;
		if(a>b)swap(a,b);
		if(a>c)swap(a,c);
		if(b>c)swap(b,c);
		int mi = max(0, c - a - b - 1);
		if(mi<=m&&m<=mx)cout<<"YES\n";
		else cout<<"NO\n";
	}
}