#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans[5];
ll price[5];
ll money(0);

void spend(void)
{
	while (money >= price[0])
	{
		int k(0);
		while (k < 5 and money >= price[k]) ++k;
		--k;
		ans[k] += money/price[k];
		money %= price[k];
	}
}

int main(void)
{
	int n; cin >> n;
	vector<int> a(n);
	for (auto& v : a) cin >> v;
	for (int i(0); i < 5; ++i)
		cin >> price[i];
	for (auto e : a)
	{
		money += e;
		spend();
	}
	for (auto e : ans)
		cout << e << ' ';
	cout << endl << money << endl;
}