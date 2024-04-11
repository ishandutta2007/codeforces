#include <bits/stdc++.h>
using namespace std;

const int MAXV = 2e4 + 1;
const int MAXN = 1e3;
const int DELTA = 1e4;
const int MOD = 1e9+7;

long long ways[MAXN][MAXV];
int arr[MAXN];

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int N;
	cin >> N;
	for (int i(0); i < N; ++i)
		cin >> arr[i];
	
	long long ans(0);
	ways[0][arr[0] + DELTA] = ways[0][DELTA-arr[0]] = 1;
	for (int i(1); i < N; ++i)
	{
		for (int j(arr[i]); j + arr[i] < MAXV; ++j)
			ways[i][j] = (ways[i-1][j-arr[i]] + ways[i-1][j+arr[i]])%MOD;
		ways[i][DELTA+arr[i]]++;
		ways[i][DELTA-arr[i]]++;
		ans = (ways[i][DELTA]+ans)%MOD;
	}
	cout << ans << endl;
}