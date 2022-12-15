#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const ll MOD = 1e9+7;
const int MAX = 1001;

ll asc[MAX][MAX];
ll desc[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	for (int len(1); len <= m; ++len)
		for (int last(1); last <= n; ++last)
		{
			if (len == 1)
				asc[len][last] = 1;
			else
				for (int bef(1); bef <= last; ++ bef)
				{
					asc[len][last] = (asc[len][last] + asc[len-1][bef])%MOD;
				}
		}
	for (int len(1); len <= m; ++len)
		for (int first(1); first<= n; ++first)
		{
			if (len == 1) desc[len][first] = 1;
			else
				for (int second(first); second <= n; ++second)
					desc[len][first] = (desc[len][first] + desc[len-1][second])%MOD;
		}
	ll ret(0);

	for (int a(1); a <= n; ++a)
		for (int b(a); b <= n; ++b)
			ret = (ret + asc[m][a]*desc[m][b])%MOD;
	cout << ret << endl;
}