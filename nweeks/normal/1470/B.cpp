#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 


int simplifyNumber(int x)
{
	int ret(1);
	for (int i(2); i*i <= x; ++i)
		if (x % i == 0)
		{
			int cnt(0);
			while (x%i == 0) ++cnt, x /= i;
			if (cnt%2)
				ret *= i; 
		}
	ret *= x;
	return ret;
}

void solve(void)
{
	int nbElem;
	cin >> nbElem;
	vector<int> elems(nbElem);
	for (auto &v : elems)
	{
		cin >> v;
		v = simplifyNumber(v);
	}
	map<int, int> cnt;
	for (auto v : elems)
		cnt[v]++;
	int retStart(0), retAfter(0);
	for (auto v : cnt)
		retStart = max(retStart, v.second);
	int totEven(0);
	for (auto v : cnt)
		if (v.second % 2 == 0 or v.first == 1)
			totEven += v.second;
	retAfter = max(retStart, totEven);
	int nbRequetes;
	cin >> nbRequetes;
	while (nbRequetes--)
	{
		ll w;
		cin >> w;
		if (w == 0) cout << retStart << '\n';
		else cout << retAfter << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();	
}