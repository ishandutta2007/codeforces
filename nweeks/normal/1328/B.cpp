#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

string solve(void)
{
	ll n, k;
	cin >> n >> k;

	ll l(1);

	while ( (n-l) *(n-l-1)/2 >= k)
		++l;
	assert(l+1 <= n);

	ll r = l+1;
	while ( (n-l) * (n-l-1)/2 + n- r >= k)
		++r;
	assert(r <= n);
	string s = "";
	for (int i(1); i < l; ++i)
		s += 'a';
	s += 'b';
	for (int i(l+1); i < r; ++i)
		s += 'a';
	s += 'b';
	for (int i(r+1); i <= n; ++i)
		s += 'a';
	return s;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		cout << solve() << '\n';
}