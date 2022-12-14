#include<cstdio>
#include<cmath>
#include<map>
#include<vector>

using namespace std;

const int maxn = 1000005;

int n, a[maxn], b[maxn], d[maxn], max1 = -1, l, max2, ans2 = 0, used[maxn];
long long sz = 0, ans = 0;
vector <int> c, pos;
map <int, int> m;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	    if (max1 < a[i])
	    {
			max1 = a[i];		
			l = i;
		}
	}
	for (int i = l; i < n; i++)
		b[i - l] = a[i];
	for (int i = 0; i < l; i++)
		b[n - l + i] = a[i];
	for (int i = 0; i < n; i++)
		if (b[i] == max1)
		{
			sz++;
			pos.push_back(i);
		}
	pos.push_back(n);
	ans += sz * (sz - 1) / 2;
	//printf("%I64d\n", ans);
	for (int i = 0; i < n; i++)
	{
		if (b[i] == max1)
		{
			for (int j = 0; j < (int) c.size(); j++)
				m[c[j]] = 0;
			c.clear();
			continue;
		}
		if ((int) c.size() == 0)
		{
			c.push_back(b[i]);
			m[b[i]] = 1;
			continue;
		}
		while(c[(int) c.size() - 1] < b[i])
		{
			ans += m[c[(int) c.size() - 1]];
			m[c[(int) c.size() - 1]] = 0;
			c.pop_back();
			if ((int) c.size() == 0)
				break;
		}
		if ((int) c.size() == 0)
		{
			c.push_back(b[i]);
			m[b[i]] = 1;
			continue;
		}
		if (b[i] == c[(int) c.size() - 1])
		{
			ans += m[b[i]];
			m[b[i]]++;
			if ((int) c.size() >= 2)
				ans++;
			continue;
		}
		if (b[i] < c[(int) c.size() - 1])
		{
			ans++;
			c.push_back(b[i]);	
			m[b[i]] = 1;
		}
   	}
	//printf("%I64d\n", ans);
	for (int i = 0; i < (int) pos.size() - 1; i++)
   	{
   		max2 = -1;
   		for (int j = pos[i] + 1; j < pos[i + 1]; j++)
   		{
   			max2 = max(max2, b[j]);	
   			if (b[j] >= max2)
   			{
   				ans++;
   				used[j] = 1;
   				ans2++;
   			}
   		}
   	}
	//printf("%I64d\n", ans);
	if (sz != 1)
	{
		for (int i = 0; i < n - 1; i++)
			d[i] = b[i + 1];
		d[n - 1] = b[0];
		pos.clear();
		for (int i = n - 1; i >= 0; i--)
			if (d[i] == max1)
				pos.push_back(i);
	   	pos.push_back(-1);
		//printf("AA2\n");
	   	for (int i = 0; i < (int) pos.size() - 1; i++)
   		{
	   		//printf("%d\n", i);
   			max2 = -1;
   			for (int j = pos[i] - 1; j > pos[i + 1]; j--)
	   		{
   				//printf("%d\n", j);
   				max2 = max(max2, d[j]);	
   				if (d[j] >= max2)
   					ans++;
	   		}	
   		}
	}
	else
	{
   		max2 = -1;
		for (int i = n - 1; i > 0; i--)
   		{
   			max2 = max(max2, b[i]);	
   			if (b[i] >= max2)
   				used[i] = 1;
   		}
   		for (int i = 0; i < n; i++)
   			if (used[i] == 1)
   				ans++;
   		ans -= ans2;
	}
	printf("%I64d\n", ans);
	return 0;
}