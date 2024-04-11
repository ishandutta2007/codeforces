#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 1e6+1;

bool prime[MAXN];
int nb_occ[MAXN];
int nb_occ2[MAXN];

void sieve()
{
	for (int i(2); i < MAXN; ++i)
		prime[i] = true;
	for (int p(2); p < MAXN; ++p)
		if (prime[p])
		{
			for (int j(2*p); j < MAXN; j += p)
				prime[j] = false;
		}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_entiers;
	cin >> nb_entiers;
	vector<ll> arr(nb_entiers);
	sieve();
	for (auto &v : arr)
	{
		cin >> v;
		nb_occ2[v]++;
	}
	for (int i(2); i < MAXN; ++i)
		for (int j(i); j < MAXN; j += i)
			nb_occ[i] += nb_occ2[j];

	ll ret(1);
	for (int p(2); p < MAXN; ++p)
		if (prime[p])
		{
			ll cur(1);
			while (cur * p < MAXN and nb_occ[cur*p] >= nb_entiers - 1)
				cur *= p;
			ret *= cur;
		}
		cout << ret << endl;
}