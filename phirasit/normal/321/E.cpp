#include <stdio.h>
#include <algorithm>
#include <stack>
#include <iostream>

#define N 4200
#define K 810
#define INF ((-1u/2) >> 3)

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PI3;

int dp[N][K];
int idx[N][K];

int val[N][N];
int sum[N][N];
int arr[N][N];
int n, k;

inline void read(int &x)
{
   char ch;bool f=0;int a=0;
   while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch=='-')));
   if(ch!='-')a*=10,a+=ch-'0';else f=1;
   while(((ch=getchar())>='0')&&(ch<='9'))a*=10,a+=ch-'0';
   if(f)a=-a;x=a;
}
int main() {
	read(n);
	read(k);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			read(arr[i][j]);
			sum[i][j] = (j > 0 ? sum[i][j-1] : 0) + arr[i][j];
		}
	}
	for(int i = n-1;i > 0;i--) {
		for(int j = i;j <= n;j++) {
			if(i >= j) {
				val[i][j] = 0;
			}else {
				val[i][j] = val[i+1][j] + sum[i][j] - sum[i][i];
			}
		}
	}
	for(int i = 1;i <= k;i++) {
		stack<PI3> stk;
		stk.push(PI3(i, PII(1, n)));
		while(!stk.empty()) {
			PI3 top = stk.top();
			stk.pop();
			int j = top.first, a = top.second.first, b = top.second.second;
			if(a > b) {
				continue;
			}
			if(j == 1) {
				dp[a][j] = val[1][a];
				idx[a][j] = 0;
				stk.push(PI3(j, PII(a+1, b)));
				continue;
			}
			int mid = (a + b) / 2;
			int max_a = max(j-1, max(a > 1 ? idx[a-1][j] : 1, idx[mid][j-1]));
			int min_b = min(mid-1, b < n ? idx[b+1][j] : n);  
			dp[mid][j] = INF;
			idx[mid][j] = max_a;
			for(int i = max_a;i <= min_b;i++) {
				int x = dp[i][j-1] + val[i+1][mid];
				if(x < dp[mid][j]) {
					dp[mid][j] = x;
					idx[mid][j] = i;
				}
			}
			stk.push(PI3(j, PII(a, mid-1)));
			stk.push(PI3(j, PII(mid+1, b)));
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}