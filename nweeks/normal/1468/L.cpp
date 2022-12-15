#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll;

ll isPrimePower(ll x)
{
	for (ll d(2); d * d <= x; ++d)
		if (x%d==0)
		{
			while (x%d==0)
				x /= d;
			return (x == 1) * d;
		}
	return x;
}

set<ll> otherNumbers;
map<ll, vector<ll>> primePowers;
vector<ll> interestingPrimes;
int n, k;
int cnt;

void case1()
{
	while (cnt > k)
	{
		ll p = interestingPrimes.back();
		interestingPrimes.pop_back();
		if (primePowers[p].empty())
			continue;
		if (SZ(primePowers[p]) % 2 == 0)
		{
			primePowers[p].pop_back();	
			primePowers[p].pop_back();	
			if (!primePowers[p].empty())
				interestingPrimes.push_back(p);
			cnt -= 2;
			continue;
		}
		assert(!interestingPrimes.empty());
		ll q = interestingPrimes.back();
		interestingPrimes.pop_back();
		if (primePowers[q].empty())
		{
			interestingPrimes.push_back(p);
			continue;
		}
		if (SZ(primePowers[q]) %2 == 0)
		{
			primePowers[q].pop_back();
			primePowers[q].pop_back();
			if (!primePowers[q].empty())
				interestingPrimes.push_back(q);
			if (!primePowers[p].empty())
				interestingPrimes.push_back(p);
			cnt -= 2;
			continue;
		}
		primePowers[p].pop_back();
		primePowers[q].pop_back();
		if (!primePowers[p].empty())
			interestingPrimes.push_back(p);
		if (!primePowers[q].empty())
			interestingPrimes.push_back(q);
		cnt -= 2;
	}
	for (auto p : interestingPrimes)
	{
		for (auto v : primePowers[p])
			cout << v << ' ';
	}
	cout << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	if (k == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	vector<ll> arr(n);
	for (auto &v : arr)
		cin >> v;
	for (auto v : arr)
	{
		if (v > (ll)1e9)
		{
			ll lo(1), up(1e9);
			while (lo <up)
			{
				ll mid = (lo + up)/2;
				if (mid * mid < v)
					lo = mid+1;
				else up = mid;
			}
			if (lo * lo == v)
			{
				ll ret = isPrimePower(lo);
				if (ret)
					primePowers[ret].push_back(v);
				else
					otherNumbers.insert(v);
			}
			else
			{
				lo = 1, up = 1e6;
				while (lo < up)
				{
					ll mid = (lo + up)/2;
					if (mid * mid * mid < v)
						lo = mid+1;
					else
						up = mid;
				}
				if (lo * lo * lo == v)
				{
					ll ret = isPrimePower(lo);
					if (ret)
						primePowers[ret].push_back(v);
					else
						otherNumbers.insert(v);
				}
				else
					otherNumbers.insert(v);
			}
		}
		else
		{
			ll ret = isPrimePower(v);
			if (ret)
				primePowers[ret].push_back(v);
			else
				otherNumbers.insert(v);
		}
	}
	vector<ll> toErase;
	for (auto v : otherNumbers)
		if (v > (ll)1e9)
			for (auto p : primePowers)
				if (v % p.first == 0)
				{
					ll w = v;
					while (v % p.first == 0)
						v /= p.first;
					if (v == 1)
					{
						primePowers[p.first].push_back(w);
						toErase.push_back(w);
					}
					break;
				}
	for (auto w : toErase)
		otherNumbers.erase(w);
	for (auto &p : primePowers)
		if (SZ(p.second) >= 2)
			interestingPrimes.push_back(p.first);

	for (auto p : interestingPrimes)
		cnt += SZ(primePowers[p]);
	int tot(SZ(otherNumbers));
	for (auto p : primePowers)
		tot += SZ(p.second);
	assert(tot == n);

	if (cnt >= k)
	{
		if (cnt % 2 == k % 2)
		{
			case1();
			return 0;
		}
		ll greater2(0);
		for (auto p : interestingPrimes)
			if (SZ(primePowers[p]) > 2)
			{
				greater2 = p;
				break;
			}
		if (greater2)
		{
			primePowers[greater2].pop_back();
			cnt--;
			case1();
			return 0;
		}
		for (auto v : otherNumbers)
		{
			ll w = v;
			int nbFacteurs(0);
			for (auto p : interestingPrimes)
				if (v % p == 0)
				{
					nbFacteurs++;
					while (v % p == 0)
						v /= p;
				}
			if (v != 1) continue;
			if (1 + nbFacteurs * 2 <= k)
			{
				cout << w << ' ';
				k--;
				for (auto p : interestingPrimes)
					if (w % p == 0)
					{
						cout << primePowers[p].back() << ' ';
						primePowers[p].pop_back();
						cout << primePowers[p].back() << ' ';
						primePowers[p].pop_back();
						k -= 2;
						cnt -= 2;
					}
				assert( k%2 == cnt%2);
				case1();
				return 0;
			}
		}
		if (k == n)
			assert(false);
		cout << 0 << endl;
		return 0;
	}
	vector<ll> take;
	for (auto p : interestingPrimes)
		for (auto v : primePowers[p])
		{
			take.push_back(v);
			k--;
		}
	for (auto v : otherNumbers)
	{
		ll w = v;
		for (auto p : interestingPrimes)
			while (w % p == 0)
				w /= p;
		if (w == 1 and k > 0)
		{
			take.push_back(v);
			k--;
		}
	}
	if (k > 0)
		cout << 0 << endl;
	else
	{
		for (auto v : take)
			cout << v << ' ';
		cout << endl;
	}
}