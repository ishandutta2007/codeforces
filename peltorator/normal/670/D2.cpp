#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

typedef long long ll;
vector < ll > a, b;
int main()
{
	ll n, K;
	cin >> n >> K;
	for (ll i = 0; i < n; i++)
	{
		a.push_back(0);
		cin >> a[i];
	}
	for (ll i = 0; i < n; i++)
	{
		b.push_back(0);
		cin >> b[i];
	}
	ll l = 0, r = 1e9;
	r *= 2;
	r++;
	while (r - l > 1)
	{
		ll med = (r + l) / 2;
		ll k = K;
		for (ll i = 0; i < n; i++)
		{
			if (b[i] < a[i] * med) k -= (a[i] * med - b[i]);
			if (k < 0) i = n + 5;
		}
		if (k < 0) r = med;
		else l = med;
	}
	cout << l;
	return 0;
}