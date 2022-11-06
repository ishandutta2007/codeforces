#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int a[MAXN + 1];
int b[MAXN + 1];
long long sum[MAXN + 1];
long long ans[MAXN];
long long c[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	c[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		sum[i] = b[i] - a[i] - sum[1];
		c[i] = -c[1];
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j)
				continue;
			sum[i] -= sum[j];
			c[i] -= c[j];
			if (j * j != i)
			{
				int k = i / j;
				sum[i] -= sum[k];
				c[i] -= c[k];
			}
		}
	}
	//for (int i = 1; i <= n; i++)
	//{
		//cout << i << " " << sum[i] << " " << c[i] << "\n";
	//}
	long long offset = 0;
	vector<tuple<long long, int, int>> events;
	int left = 0;
	int right = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!c[i])
			offset += abs(sum[i]);
		else
		{
			events.push_back({-sum[i] * c[i], 0, -1});
			right++;
		}
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		x -= a[1];
		events.push_back({x, 1, i});
	}
	sort(events.begin(), events.end());
	int ptr = 0;
	while (ptr < (int) events.size())
	{
		tuple<long long, int, int> tup = events[ptr];
		int type = get<1>(tup);
		if (type == 1)
			break;
		right--;
		left++;
		ptr++;
	}
	long long cur_time = get<0>(events[ptr]);
	long long cur_ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!c[i])
			continue;
		cur_ans += abs(sum[i] + cur_time * c[i]);
	}
	while (ptr < (int) events.size())
	{
		tuple<long long, int, int> tup = events[ptr];
		int type = get<1>(tup);
		long long when = get<0>(tup);
		long long diff = when - cur_time;
		cur_ans += (left - right) * diff;
		cur_time = when;
		if (type == 0)
		{
			left++;
			right--;
		}
		else if (type == 1)
		{
			ans[get<2>(events[ptr])] = cur_ans;
		}
		ptr++;
	}
	for (int i = 0; i < q; i++)
	{
		cout << ans[i] + offset << "\n";
	}
	return 0;
}