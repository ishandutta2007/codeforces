#include"bits/stdc++.h"

using namespace std;


int n;

#define MAX 1000002

int dp[MAX];


void calc(int num,int r=2) {
	int tmp = num;
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) {
			while(num%i==0)num /= i;
			int VAL = i;  //selected number
			int le = ((tmp - 1) / VAL)*VAL;
			dp[le + 1]++;
			dp[tmp + 1]--;
		}
	}
	if (num>1) {
		int i = num; 
		int VAL = i;  //selected number
		int le = ((tmp - 1) / VAL)*VAL;
		dp[le + 1]++;
		dp[tmp + 1]--;
	}
}

int pr[MAX];
int main() {
	memset(pr, -1, sizeof(pr));
	cin >> n;
	calc(n, 2); 
	for (int i = 2; i < MAX; i++) {
		if (pr[i] == -1) {
			pr[i] = i;
			for (int j = i * 2; j < MAX; j+=i) {
				pr[j] = i;
			}
		}
	}
	for (int i = 1; i < MAX; i++) {
		dp[i] += dp[i - 1];
	}
	int ans = INT_MAX;
	for (int ii = 3; ii < MAX; ii++) {
		if (dp[ii] == 0)continue;
		int i = ii;
		int tmp = ii;
		while (i != 1) {
			int VAL = pr[i];  //selected number
			if (tmp == VAL) {
				i /= pr[i];
				continue;
			}
			int le = ((tmp - 1) / VAL)*VAL;
			ans = min(ans, max(3,le + 1) );
			i /= pr[i];
		}
	}
	cout << ans << endl;
	return 0;
}