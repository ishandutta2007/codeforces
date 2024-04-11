#include <bits/stdc++.h>
#define endl '\n';
 
typedef long long ll;
 
using namespace std;
 
int n, m;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
	vector<ll> a;
	vector<ll> b;
	vector<int> bit;
	cin >> n >> m;
	bit.resize(31);
 
	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < m; i++)
	{
		ll x;
		cin >> x;
		b.push_back(x);
	}
 
	for(int i = 0; i<n; i++)
	{
		ll temp = a[i];
		int j = 0;
		while (temp)
		{
			if (temp & 1)
				bit[j]++;
 
			temp /= 2;
			j++;
		}
	}
 
	sort(b.begin(), b.end());
	ll c = 0;
 
	for (int i = 0; i < b.size(); i++)
	{
		if (bit[b[i]] > 0)
		{
			c++;
			bit[b[i]]--;
		}
		else
		{
			for (int j = b[i]; j < bit.size(); j++)
			{
				if (bit[j] > 0)
				{
					c++;
					bit[j]--;
					for(int k = b[i]; k<j; k++)
						bit[k]++;
					break;
				}
			}
		}
	}
	cout << c;
}