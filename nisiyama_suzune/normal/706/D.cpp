//IO
#include <iostream>
#include <cstdio>
#include <iomanip>

//General
#include <cmath>
#include <cstdlib>
#include <cstring>

//STL
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

typedef long long llong;

const int INF = 1E9;

multiset <llong> S;
int N;

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N;
	S.insert (0);
	for (llong i = 1; i <= N; i++) {
		char c;
		llong x;
		cin >> c >> x;
		if (c == '+')
			S.insert (x);
		if (c == '-')
			S.erase (S.find (x));
		if (c == '?') {
			llong ans = 0;
			for (llong i = 30; i >= 0; i--) {
				multiset <llong>::iterator itb = S.lower_bound (ans + (((~(x >> i)) & 1LL) << i));
				multiset <llong>::iterator ite = S.upper_bound (ans + (((~(x >> i)) & 1LL) << i) + (1LL << i) - 1LL);
				if (itb == ite)
					ans += (((x >> i) & 1LL) << i);
				else
					ans += (((~(x >> i)) & 1LL) << i);
			}
			cout << (x ^ ans) << endl;
		}
	}
	return 0;
}