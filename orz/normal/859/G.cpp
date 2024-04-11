//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define ll long long
#define ld long double

using namespace std;


int main()
{
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	string s;
	cin >> n;
	getline(cin, s);
	getline(cin, s);
	vector<ll> numb(n);
	vector<ll> pr;
	vector<ll> pw;
	vector<ll> prpw;
	vector<ll> kr(n);
	vector<ll> kek(n);
	ll nn = n;
	for (ll i = 2; i <= nn; ++i)
	{
		if (n % i == 0)
		{
			pr.push_back(i);
			ll u = 0, w = 1;
			while (n % i == 0)
			{
				n /= i;
				++u;
				w *= i;
			}
			pw.push_back(u);
			prpw.push_back(w);
		}
	}
	n = nn;
	for (ll i = 0; i < n; ++i)
	{
		kr[i] = 0;
		kek[i] = -1;
		numb[i] = s[i] - '0';
		for (ll j = 0; j < pr.size(); ++j)
		if (((i % prpw[j]) / (prpw[j] / pr[j])) == 0)
		{
			++kr[i];
			if (kek[i] == -1)
				kek[i] = j;
		}
	}
	for (ll i = pr.size(); i > 0; --i)
	{
		for (ll j = 0; j < n; ++j)
		if ((kr[j] == i) && (numb[j]))
		{
			//cout << "prime " << pr[kek[j]] << " for " << j << ':';
			//for (int i = 0; i < n; ++i)
			//	cout << numb[i] << ' ';
			ll x = numb[j];
			for (ll k = 0; k < pr[kek[j]]; ++k)
			{
				numb[(j + k * (n / pr[kek[j]])) % n] -= x;
			}
			//cout << '\n';
		}
	}
	//for (int i = 0; i < n; ++i)
	//	cout << numb[i] << ' ';
	//cout << '\n';
	bool zz = true;
	for (ll i = 0; zz && (i < n); ++i)
		zz = (numb[i] == 0);
	if (zz)
		cout << "YES\n";
	else
		cout << "NO\n";
	//cout << s;
	return 0;
}