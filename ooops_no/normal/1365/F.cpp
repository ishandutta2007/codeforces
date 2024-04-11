#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
//#include<unordered_set>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> st;*/

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		if (n % 2 == 1)
		{
			if (a[n / 2] != b[n / 2])
			{
				cout << "No\n";
				continue;
			}
			else
			{
				vector<int> v;
				for (int i = 0; i < n / 2; i++)
				{
					v.pb(a[i]);
				}
				for (int i = n / 2 + 1; i < n; i++)
				{
					v.pb(a[i]);
				}
				a = v;
			}
		}
		int i = a.size() / 2 - 1, j = a.size() / 2 + n % 2;
		bool x = 1;
		while (x && a.size() > 0)
		{
			bool check = 0;
			for (int k = 0; k < a.size() / 2; k++)
			{
				if (a[k] == b[i] && a[a.size() - k - 1] == b[j])
				{
					for (int l = 0; l <= k; l++)
					{
						swap(a[l], a[a.size() - k - 1 + l]);
					}
					for (int l = 0; l < a.size() / 2; l++)
					{
						swap(a[l], a[a.size() - a.size() / 2 + l]);
					}
					check = 1;
				}
				if (a[k] == b[j] && a[a.size() - k - 1] == b[i] && !check)
				{
					for (int l = 0; l <= k; l++)
					{
						swap(a[l], a[a.size() - k - 1 + l]);
					}
					swap(a[0], a[a.size() - 1]);
					for (int l = 0; l < a.size() / 2; l++)
					{
						swap(a[l], a[a.size() - a.size() / 2 + l]);
					}
					check = 1;
				}
				if (check)
				{
					vector<int> v;
					for (int k = 0; k < a.size() / 2 - 1; k++)
					{
						v.pb(a[k]);
					}
					for (int k = a.size() / 2 + 1; k < a.size(); k++)
					{
						v.pb(a[k]);
					}
					a = v;
					i--, j++;
					break;
				}
			}
			if (!check) {
				x = 0;
			}
		}
		if (x) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}