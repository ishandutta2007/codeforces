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

int A[200000] = {0};

int lowbit (int x) {
	return x & (-x);
}

void Add (int d, int x) {
	while (x < 190000) {
		A[x] += d;
		x += lowbit (x);
	}
}

int Query (int x) {
	int ans = 0;
	while (x > 0) {
		ans += A[x];
		x -= lowbit (x);
	}
	return ans;
}

int N;
int a;

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		Add (1, a);
	}
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		if (a > 180000) a = 180000;
		cout << Query (a) << endl;
	}
	return 0;
}