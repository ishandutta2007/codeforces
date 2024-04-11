#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 500;

int A[N], n, dp[N][2];

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", A + i);
		if(A[i] < 0)
			A[i] *= -1;
	}
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			if(A[i] < A[j])
				dp[j][1]++;
			if(A[i] > A[j])
				dp[i][0]++;
		}
	}
	int sol = 0;
	for(int i = 0;i < n;i++)
		sol += min(dp[i][0], dp[i][1]);
	printf("%d\n", sol);
}