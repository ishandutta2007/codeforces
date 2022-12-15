#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

void print_binary(ll a)
{
	string s = "";

	while (a)
		s += char(a%2+'0'), a/=2;
	cout << s << endl;
}

int main(void)
{
	ll l, r; cin >> l >> r;

	ll a, b;
	long long k(62);
	if (l == r)
		cout << 0 << endl;
	else
	{
		while (k >= 0 and (l & (1ULL<<k)) == (r & (1ULL<<k)))
			k--;
		cout << (1ULL<<(k+1)) - 1 << endl;
	}
}