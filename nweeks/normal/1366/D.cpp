#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())

using ll = long long;

const int MAXN = 1e7+1;
bool prime[MAXN];
int greatestDiv[MAXN];

void sieve(void)
{
	for (int i(2); i < MAXN; ++i)
		prime[i] = true;
	for (int p(2); p < MAXN; ++p)
		if (prime[p])
		{
			greatestDiv[p] = p;
			for (int j(2*p); j < MAXN; j += p)
			{
				prime[j] = false;
				if (greatestDiv[j/p] % p == 0)
					greatestDiv[j] = p * greatestDiv[j/p];
				else
					greatestDiv[j] = p;
			}
		}
}

void solve()
{
	int nbElem;
	cin >> nbElem;
	vector<int> arr(nbElem);
	for (auto &v : arr) cin >> v;
	sieve();
	for (int i(0); i < nbElem; ++i)
		cout << (greatestDiv[arr[i]] == arr[i] ? -1 : greatestDiv[arr[i]]) << ' ';
	cout << endl;
	for (int i(0); i < nbElem; ++i)
		cout << (greatestDiv[arr[i]] == arr[i] ? -1  : arr[i]/greatestDiv[arr[i]]) << ' ';
	cout << endl;

}

int main(void)
{
	int nbTests(1);
	//cin >> nbTests;
	for (int i(0); i < nbTests; ++i)
		solve();
}