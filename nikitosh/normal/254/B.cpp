#include<cstdio>
#include<algorithm>

using namespace std;

int max1 = -1000000000, n, m[200], d[200], p[200], t[200], c, beg[200], end[200];

int foo(int a, int b)
{
	int ans = 0;
	a--;
	if (a == 0)
		ans = 0;
	if (a >= 1)
		ans += 31;
	if (a >= 2)
		ans += 28;
	if (a >= 3)
		ans += 31;
	if (a >= 4)
		ans += 30;
	if (a >= 5)
		ans += 31;
	if (a >= 6)
		ans += 30;
	if (a >= 7)
		ans += 31;
	if (a >= 8)
		ans += 31;
	if (a >= 9)
		ans += 30;
	if (a >= 10)
		ans += 31;
	if (a >= 11)
		ans += 30;
	if (a >= 12)
		ans += 31;
	ans += b;
	return ans;
}

int main()
{                                  
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &m[i], &d[i], &p[i], &t[i]);
		c = foo(m[i], d[i]);
		beg[i] = c - t[i];
		end[i] = c - 1;
	}
	for (int i = -500; i < 500; i++)
	{
		int ans1 = 0;
		for (int j = 0; j < n; j++)
		{
			if (beg[j] <= i && i <= end[j])
				ans1 += p[j]; 
		}
		max1 = max(max1, ans1);           
	}
	printf("%d\n", max1);
	return 0;
}