
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

int N;
int A[500000];

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort (A, &A[N]);
	cout << A[(N - 1) / 2] << endl;
	return 0;
}