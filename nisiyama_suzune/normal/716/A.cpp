
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

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int N, ans = 0, tl;
	cin >> N >> tl;
	int ls = 0, a = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a - ls > tl)
			ans = 1;
		else
			ans++;
		ls = a;
	}
	cout << ans << endl;
	return 0;
}