#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
ll n;
int m;
ll dp[60000][105];
int base[10];
int val[15];
int num[10];
int total;
int main()
{
	cin >> n >> m;
	total = 0;
	while (n > 0){
		num[n % 10]++;
		n /= 10;
	}
	val[0] = 1;
	for (int i = 0; i < 10; ++i){
		base[i] = num[i] + 1;
		val[i + 1] = base[i] * val[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i < val[10]; ++i)
		for (int j = 0; j < 10; ++j){
			if (j == 0 && i < val[1])continue;
			if (i / val[j] % base[j] >= num[j])continue;
			for (int k = 0; k < m; ++k)
				dp[i + val[j]][(k * 10 + j) % m] += dp[i][k];
		}
	cout << dp[val[10] - 1][0] << endl;
	return 0;
}