#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const int MAXN = 5000;

ll sol[MAXN][MAXN];
ll last_step[MAXN][MAXN];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i(0); i < n; ++i)
		cin >> sol[0][i];
	
	for (int depth(1); depth <= n; ++depth)
		for (int i(0); i+depth < n; ++i)
			sol[depth][i] = sol[depth-1][i] ^ sol[depth-1][i+1];
	for (int depth(1); depth < n; ++depth)
		for (int i(0); i + depth < n; ++i)
			sol[depth][i] = max({sol[depth][i], sol[depth-1][i],
									sol[depth-1][i+1]});
	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		--l,--r;
		cout << sol[r-l][l] << '\n';
	}
}