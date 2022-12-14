#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int n, ww, hh, pr[5005], d[5005], boo, max1 = -1000000001, l;
vector <int> ans;

struct st
{
 	int w, h, z;
};

st a[5005];

bool foo (st a, st b)
{
	if (a.w <= b.w && a.h <= b.h)
		return 1;
	if (a.w > b.w && a.h > b.h)
		return 0;
	if (a.w == b.w)
		return a.z < b.z;
	return a.w < b.w;
	return 1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &ww, &hh);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].w, &a[i].h);
		a[i].z = i + 1;
	}
	sort(a, a + n, foo);
	for (int i = 0; i < n; i++)
	{
		if (ww >= a[i].w || hh >= a[i].h)
		{
			d[i] = -1000000000;
	   		pr[i] = -1;
			continue;
	   	}
		d[i] = -1;
		boo = 0;
		for (int j = 0; j < i; j++)
			if (d[j] > 0 && a[j].h < a[i].h && a[j].w < a[i].w && d[j] + 1 > d[i])
			{
				boo = 1;
				d[i] = d[j] + 1;
				pr[i] = j;
		   	}
		if (boo == 0)
		{
			d[i] = 1;
			pr[i] = -1;
	   	}
	}
	for (int i = 0; i < n; i++)
		if (max1 < d[i])
		{
			max1 = d[i];
			l = i;
		}
   	printf("%d\n", max(max1, 0));
   	if (max1 <= 0)
   		return 0;
	while (l != -1)
	{
		ans.push_back(a[l].z);
		l = pr[l];
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d ", ans[i]);
	return 0;
}