#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int m[MAXN];
int k[MAXN];
int cnt[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m[i] >> k[i];
	}
	//n = MAXN;
	//for (int i = 0; i < MAXN; i++)
	//{
		//m[i] = i % 20 + 1;
		//k[i] = 20;
	//}
	vector<int> ans;
	int num = 0;
	int den = 1;
	for (int i = 1; i <= 20; i++)
	{
		//cout << "iter " << i << endl;
		for (int j = 0; j < n; j++)
		{
			if (k[j] >= i)
			{
				cnt[m[j]]++;
			}
		}
		vector<pair<int, int>> vec2;
		for (int j = 1; j <= MAXN; j++)
		{
			if (cnt[j])
				vec2.push_back({cnt[j], j});
		}
		if ((int) vec2.size() < i)
			continue;
		sort(vec2.rbegin(), vec2.rend());
		int sum2 = 0;
		for (int j = 0; j < min(i, (int) vec2.size()); j++)
		{
			sum2 += vec2[j].first;
		}
		if ((long long) sum2 * den > (long long) num * (i))
		{
			num = sum2;
			den = i;
			ans.clear();
			for (int j = 0; j < i; j++)
				ans.push_back(vec2[j].second);
		}
	}
	vector<pair<int, int>> vec;
	for (int i = 1; i <= MAXN; i++)
	{
		vec.push_back({cnt[i], i});
	}
	sort(vec.rbegin(), vec.rend());
	int sum = 0;
	bool flag = false;
	for (int i = 0; i < (int) vec.size(); i++)
	{
		sum += vec[i].first;
		//if (i <= 30)
		//{
			//cout << "sum " << i << " " << sum << endl;
			//cout << fixed << setprecision(2) << (sum + 0.0) / (i + 1) << endl;
			//cout << fixed << setprecision(2) << (double) num / den << endl;
		//}
		if (i >= 19 && (long long) sum * den >= (long long) num * (i + 1))
		{
			num = sum;
			den = i + 1;
			flag = true;
		}
	}
	if (flag)
	{
		ans.clear();
		for (int i = 0; i < den; i++)
			ans.push_back(vec[i].second);
	}
	cout << ans.size() << "\n";
	for (int x : ans)
		cout << x << " ";
	cout << "\n";
	return 0;
}