#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve(void)
{
	int n, a, b;
	cin >> n >> a >> b;
	string s = "";
	for (int c(0); c < b; ++c)
		s += (char)(c+'a');
	for (int i(0); i < n; ++i)
		cout << s[i%b];
	cout << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	cin >> __t;
	while (__t--)
		solve();
}