
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
int Magic[100][100];

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N;
	int odd = 1, even = 2;
	for (int i = 0; i < N; i++) {
		int j;
		for (j = 0; j < abs (N - 2 * i - 1) / 2; j++) {
			Magic[i][j] = even;
			even += 2;
		}
		for (; j < N - abs (N - 2 * i - 1) / 2; j++) {
			Magic[i][j] = odd;
			odd += 2;
		}
		for (; j < N; j++) {
			Magic[i][j] = even;
			even += 2;
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cout << Magic[i][j] << " \n"[j == N - 1];
	return 0;
}