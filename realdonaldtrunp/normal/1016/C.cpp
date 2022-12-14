#include"bits/stdc++.h"
using namespace std;

int n;

int a[2][300005];

long long int fr[2][300005];
long long int sm[2][300006];

int main(){
	cin >> n;
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	{
		long long int sum[] = { 0, 0 };
		long long int len = -1;
		for (int i = n-1; i>=0; i--){
			fr[0][i] = fr[0][i + 1];
			fr[1][i] = fr[1][i + 1];
			len += 2;
			fr[0][i] += len*a[1][i]+sum[0];
			fr[1][i] += len*a[0][i]+sum[1];
			sum[0] += a[0][i]+a[1][i];
			sum[1] += a[1][i]+a[0][i];
			sm[0][i]= sum[0];
			sm[1][i] = sum[1];
		}
	}
	long long int ans = 0;
	long long int z[] = { 0, LLONG_MIN };
	long long int tim = 0;
	for (int i = 0; i < n; i++){
		ans = max(ans, fr[0][i]+sm[0][i]*tim+z[0]);
		ans = max(ans, fr[1][i]+sm[1][i]*tim+z[1]);
		z[0] += a[0][i] * tim;
		z[1] += a[1][i] * tim;
		tim++;
		swap(z[0], z[1]);
		z[0] += a[0][i]*tim;
		z[1] += a[1][i]*tim;
		tim++;
		ans = max(ans, z[0]);
		ans = max(ans, z[1]);
	}
	printf("%lld\n", ans);
	return 0;
}