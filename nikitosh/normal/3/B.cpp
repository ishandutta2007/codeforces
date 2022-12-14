#include<cstdio>
#include<algorithm>

using namespace std;

int n, v, t, l, sum[100005], ans = 0, l1 = 0, s = 0, sz1 = 0, sz2 = 0, VVV;

struct st
{
 	int x, y;
};

st a[100005], b[100005];

bool foo (st a, st b)
{
	return a.x > b.x;
}

int main()
{
	scanf("%d%d", &n, &v);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &t, &l);
		VVV += t;
		if (t == 1) 
		{
			a[sz1].x = l;
			a[sz1++].y = i + 1;
		}
		else
		{
			b[sz2].x = l;
			b[sz2++].y = i + 1;
		}
	}
	v = min(v, VVV);
	sort(a, a + sz1, foo);
	sort(b, b + sz2, foo);
	for (int i = 0; i < sz1; i++)       
		sum[i + 1] = sum[i] + a[i].x;
	ans = sum[min(v, sz1)];
	l1 = min(v, sz1);
	for (int i = 0; i < sz2; i++)
	{
		if (2 * (i + 1) > v)
			break;
		s += b[i].x;
		if (ans < s + sum[min(v - 2 * (i + 1), sz1)])
		{
			ans = s + sum[min(v - 2 * (i + 1), sz1)];
			l1 = min(v - 2 * (i + 1), sz1);
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < l1; i++)
		printf("%d ", a[i].y);
	for (int i = 0; i < (v - l1) / 2; i++)
		printf("%d ", b[i].y);
	return 0;
}