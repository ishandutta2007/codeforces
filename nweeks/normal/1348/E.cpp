#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAX = 501;

bool can[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	can[0][0] = true;
	int nb_shrubs, capacite;
	cin >> nb_shrubs >> capacite;

	ll cumua(0), cumub(0);

	for (int i(0); i < nb_shrubs; ++i)
	{
		int a, b;
		cin >> a >> b;
		for (int left_b(0); left_b < capacite; ++left_b)
			if (can[i][left_b])
			{
				int left_a = (cumua +cumub - left_b)%capacite;
				int have_a = a + left_a;
				int have_b = b + left_b;
				for (int take_b(0); take_b <= min(capacite-1, b); ++take_b)
					if ((capacite - take_b)%capacite <= a)
						can[i+1][(have_b- take_b)%capacite] = true;
			}
		cumua += a;
		cumub += b;
	}
	ll ans(0);
	for (int left_b(0); left_b < capacite; ++left_b)
		if (can[nb_shrubs][left_b])
		{
			ll get = (cumua+cumub-left_b)/capacite;
			ans = max(ans, get);
		}
	cout << ans << endl;
}