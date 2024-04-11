#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <memory.h>
#include <iomanip>
#include <set>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 2e18 + 123;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int) x.size())
#define all(x) (x).begin(), (x).end()

template<typename A, typename B> bool mini(A &x, const B &y) {
	if (y < x) {
		x = y;
		return 1;
	}
	return 0;
}

void run();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	run();
#ifdef _DEBUG
	cerr << "OK" << endl;
	while (1);
#endif
	return 0;
}

int cnt[256];
int n;

string ans[400002];

bool f(int k)
{
	int len = n / k;
	bool good = 1;
	if (len % 2 == 0)
	{
		for (int i = 0; i < 256; i++)
		{
			if (cnt[i] % 2 == 1)
			{
				return false;
			}
		}

		int ptr = 0;
		for (int i = 0; i < k; i++)
		{
			int j = 0;
			while (j < len / 2)
			{
				if (cnt[ptr] >= 2)
				{
					++j;
					cnt[ptr] -= 2;
					ans[i].push_back(ptr);
				}
				else
				{
					++ptr;
				}
			}
		}
	}
	else
	{
		int even_cnt = 0;
		for (int i = 0; i < 256; i++) even_cnt += cnt[i] / 2;
		if (len / 2 * k > even_cnt)
		{
			return false;
		}
		int ptr = 0;
		for (int i = 0; i < k; i++)
		{
			int j = 0;
			while (j < len / 2)
			{
				if (cnt[ptr] >= 2)
				{
					++j;
					cnt[ptr] -= 2;
					ans[i].push_back(ptr);
				}
				else
				{
					++ptr;
				}
			}
		}
		ptr = 0;
		for (int i = 0; i < k; i++)
		{
			while (cnt[ptr] == 0)
			{
				++ptr;
			}
			cnt[ptr]--;
			ans[i].push_back(ptr);
		}
	}
	return true;
}

void run() {
	cin >> n;
	string s;
	cin >> s;
	vector<int> d;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			d.push_back(i);
			if (n / i != i)
			{
				d.push_back(n / i);
			}
		}
	}
	
	for (int i = 0; i < n; ++i)
	{
		++cnt[s[i]];
	}

	sort(all(d));

	for (int i : d)
	{
		if (f(i))
		{
			cout << i << "\n";
			int len = n / i;
			for (int j = 0; j < i; j++)
			{
				if (len % 2 == 0)
				{
					for (int t = 0; t < sz(ans[j]); t++)
					{
						cout << ans[j][t];
					}
					for (int t = sz(ans[j]) - 1; t >= 0; t--)
					{
						cout << ans[j][t];
					}
				}
				else
				{
					for (int t = 0; t < sz(ans[j]) - 1; t++)
					{
						cout << ans[j][t];
					}
					cout << ans[j].back();
					for (int t = sz(ans[j]) - 2; t >= 0; t--)
					{
						cout << ans[j][t];
					}
				}
				cout << " ";
			}
			return;
		}
	}

}