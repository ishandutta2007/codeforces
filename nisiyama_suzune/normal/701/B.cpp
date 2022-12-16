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

int N, M;
int R[110000], C[110000], RC, CC;
long long ans;

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N >> M;
	ans = 1LL * N * N;
	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		if (R[x] == 0)
		{
			ans -= 1LL * (N - CC);
			RC++;
			R[x] = 1;
		}
		if (C[y] == 0)
		{
			ans -= 1LL * (N - RC);
			CC++;
			C[y] = 1;
		}
		cout << ans << " \n"[i == M - 1];
	}
	return 0;
}