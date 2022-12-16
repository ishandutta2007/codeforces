
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
	long long level, num = 2;
	cin >> level;
	for (long long i = 2; i < level + 2; i++) {
		if (i == 2)
			cout << 2 << endl;
		else
			cout << i * i * i - i * i - i + 2 << endl;
	}
	return 0;
}