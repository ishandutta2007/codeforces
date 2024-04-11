#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int a, b, c, d, m=0, v=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c >>d;
	m = max(3*a/10, a-a*c/250);
	v = max(3*b/10, b-b*d/250);
	if (m>v) cout << "Misha";
	else if (m==v) cout << "Tie";
	else cout << "Vasya";
	return 0;
}