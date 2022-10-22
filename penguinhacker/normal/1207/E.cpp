#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int ans=0, a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cout << "? ";
	for (int i=0; i<100; ++i)
		cout << i << ' ';
	cout << '\n';
	cout.flush();
	cin >> a;
	cout << "? ";
	for (int i=1; i<=100; ++i)
		cout << i*(1<<7) << ' ';
	cout << '\n';
	cout.flush();
	cin >> b;
	for (int i=13; i>=7; --i)
		if (a&(1<<i))
			ans+=(1<<i);
	for (int i=6; ~i; --i)
		if (b&(1<<i))
			ans+=(1<<i);
	cout << "! " << ans << '\n';
	cout.flush();
	return 0;
}