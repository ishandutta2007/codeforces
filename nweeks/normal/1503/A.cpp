#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(void)
{
	int nbElem;
	cin >> nbElem;
	string s;
	cin >> s;

	vector<int> freePositions;
	vector<int> a(nbElem), b(nbElem);
	int nb0(0);
	for (int iCar = 0; iCar < nbElem; ++iCar) 
		if (s[iCar] == '0')
		{
			if (nb0%2)
				a[iCar] = -1, b[iCar] = 1;
			else
				a[iCar] = 1, b[iCar] = -1;
			nb0++;
		}
	if (nb0 % 2)
	{
		cout << "NO\n";
		return ;
	}
	int nb1 = (nbElem - nb0) / 2;
	int deltaG(0), deltaD(0);
	for (int iCar(0); iCar < nbElem; ++iCar)
	{
		if (a[iCar])
		{
			deltaG += a[iCar];
			deltaD += b[iCar];
		}
		else
		{
			if (nb1 > 0)
			{
				a[iCar] = b[iCar] = 1, deltaG++, deltaD++;
				--nb1;
			}
			else
				a[iCar] = b[iCar] = -1, deltaG--, deltaD--;
		}
		if (deltaG < 0 or deltaD < 0)
		{
			cout << "NO\n";
			return;
		}
	}
	if (deltaG or deltaD)
	{
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	for (auto c : a)
		cout << (c == 1 ? '(' : ')');
	cout << '\n';
	for (auto c : b)
		cout << (c == 1 ? '(' : ')');
	cout << '\n';
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbTests;
	cin >> nbTests;
	while ((nbTests--))
		solve();
}