#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int N = 5e5+1;
const int sN = 700;

int arr[N];
int sum[sN][sN];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int q;
	cin >> q;
	while (q--)
	{
		int t, x, y;
		cin >> t >> x >> y;

		if (t==2)
		{
			if (x < sN)
				cout << sum[x][y] << '\n';
			else
			{
				int ans(0);
				for (int i(y); i < N; i += x)
					ans += arr[i];
				cout << ans << '\n';
			}
		}
		else
		{
			for (int m(1); m < sN; ++m)
				sum[m][ x%m ] -= arr[x];
			arr[x] += y;
			for (int m(1); m < sN; ++m)
				sum[m][ x%m ] += arr[x];
		}
	}
}