#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

void solve(void)
{
	int a, b, c;
	cin >> a >> b >> c;

	int cnt(0);
	if (a < b)
		swap(a,b);
	if (b < c)
		swap(b, c);
	if (a < b)
		swap(a, b);
	if (b < c)
		swap(b,c);
	if (a)
		cnt++, a--;
	if (b)
		cnt++, b--;
	if (c)
		cnt++, c--;
	if (a and b)
		cnt++, a--, b--;
	if (a and c)
		cnt++, a--, c--;
	if (b and c)
		cnt++, b--, c--;
	if (a and b and c)
		cnt++;
	cout << cnt << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--)
		solve();
}