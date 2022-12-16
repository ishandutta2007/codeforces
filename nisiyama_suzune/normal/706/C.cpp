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

const llong INF = 1E9;

llong N;
llong C[200000];
string str[200000][2];

llong DP[200000][2];

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> C[i];
	for (int i = 1; i <= N; i++) {
		cin >> str[i][0];
		str[i][1].resize (str[i][0].size ());
		for (int j = 0; j < str[i][0].size (); j++)
			str[i][1][j] = str[i][0][str[i][0].size () - j - 1];
	}
//	cout << str[2][0] << " " << str[2][1] << endl;
	DP[1][0] = 0; DP[1][1] = C[1];
	for (int i = 2; i <= N; i++) 
		for (int j = 0; j < 2; j++) {
			DP[i][j] = -1;
			for (int k = 0; k < 2; k++) 
				if (DP[i - 1][k] != -1 && str[i][j] >= str[i - 1][k]) {
					llong cost = DP[i - 1][k] + ((j == 0) ? 0 : C[i]);
					if (DP[i][j] == -1 || DP[i][j] > cost)
						DP[i][j] = cost;
				}
		}
//	cout << DP[2][0] << " " << DP[2][1] << endl;
	if (DP[N][0] == -1)
		cout << DP[N][1] << endl;
	else {
		if (DP[N][1] == -1)
			cout << DP[N][0] << endl;
		else
			cout << min (DP[N][0], DP[N][1]) << endl;
	}
	return 0;
}