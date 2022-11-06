#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int A, B, W, D, L;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B;
	for (int i = 1; i <= 6; i++) {
		if (llabs(i - A) == llabs(i - B)) D++;
		else if (llabs(i - A) > llabs(i - B)) L++;
		else W++;
	}
	cout << W << ' ' << D << ' ' << L << '\n';
}