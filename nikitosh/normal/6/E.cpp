#include<cstdio>
#include<algorithm>
#include<set>

using namespace std;

int n, k, a[100005], l1, l2, ans, min1, max1, sz, d[100005];
multiset <int> s;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	l1 = 0;
	l2 = 0;
	for (int i = 0; i < n; i++)
		d[i] = 1;
	ans = 1;
	s.insert(a[l1]);
	while(l2 != n - 1)
	{
		//printf("%d %d\n", l1, l2);
		s.insert(a[l2 + 1]);
		max1 = *s.rbegin();
		min1 = *s.begin();
		//printf("minmax %d %d\n", min1, max1);
		if (min1 + k >= max1)
		{
			l2++;
		    ans = max(ans, l2 - l1 + 1);
		    d[l1] = l2 - l1 + 1;
		}
		else
		{
			multiset<int>::iterator it = s.find(a[l2 + 1]);
			s.erase(it);
			max1 = *s.rbegin();
			min1 = *s.begin();
			//printf("minmax %d %d\n", min1, max1);
			it = s.find(a[l1]);
			s.erase(it);
			l1++;
			if (l1 > l2)
			{
				l2++;
				s.insert(a[l1]);
			}
		}
	}
	ans = max(ans, l2 - l1 + 1);
	printf("%d ", ans);
	for (int i = 0; i < n; i++)
		if (d[i] == ans)
			sz++;
	printf("%d\n", sz);
	for (int i = 0; i < n; i++)
		if (d[i] == ans)
			printf("%d %d\n", i + 1, i + ans);
	return 0;
}