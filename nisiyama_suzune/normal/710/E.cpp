
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

const int INF = 1E9;

long long N, X, Y;
long long DP[20000000];

long long dp (long long n) {
	if (n == 1) return X;
	if (DP[n] != 0) return DP[n];
	if (n % 2) DP[n] = min (dp (n - 1) + X, dp ((n + 1) / 2) + X + Y);
	else DP[n] = min (dp (n - 1) + X, dp (n / 2) + Y);
	return DP[n];
}

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
//	cout << (sizeof (DP) >> 20) << endl;
	cin >> N >> X >> Y;
	cout << dp (N) << endl;
	return 0;
}