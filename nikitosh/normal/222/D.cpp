#include<cstdio>
#include<algorithm>

using namespace std;

int n, x, a[200000], b[200000], p, q, ans1, ans2; 

int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);         
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);   
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] < x)
		{
			p = x - a[i];
			q = lower_bound(b, b + n, p) - b;
			if (q < n)
				if (ans1 < n - q)
					ans1++;
		}
		else
			ans1++;
 	}                    
 	//for (int i = n - 1; i >= 0; i--)
	//{
	//	if (a[i] <= x)
	//	{
	//		p = x - a[i];
	//		q = upper_bound(b, b + n, p) - b - 1;
	//		printf("q = %d\n", q);
	//		if (q > ans2 - 1)
	//			ans2++;
	//	}       
 	//}                          
 	printf("%d %d\n", 1, ans1);
	return 0;
}