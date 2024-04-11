//============================================================================
// Name        : 544E.cpp
// Author      : Daxi the Taxi
// Version     :
// Copyright   : ALL YOUR CODE IS BELONG TO US
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

const int MAX = 5001;
int n, k,
	arr[MAX], dp[MAX][MAX];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < n; ++j) {
			int backIdx = (lower_bound(arr, arr + n, arr[j] - 5) - arr) - 1;

			if(backIdx < 0)
				dp[i][j] = j + 1;
			else
				dp[i][j] = dp[i - 1][backIdx] + j - backIdx;

			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
		}
	}

//	printf("dp: [\n");
//	for(int i = 0; i < k + 1; i++){
//		printf("%d : ", i);
//		for(int j = 0; j < n; j++){
//			printf("%d, ", dp[i][j]);
//		}
//		printf("\n");
//	}
//	printf("]\n");

	printf("%d\n", dp[k][n - 1]);
}