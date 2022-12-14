#include<cstdio>
#include<algorithm>

using namespace std;

int s, k, a[100000], b[100000], ans, m;

int main()
{
	scanf("%d%d", &s, &k);
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	for (int i = 3; i < 10000; i++)
	{
		a[i] = a[i - 1] + a[i - 1] - a[max(0, i - k - 1)];
		if (a[i] > s)
		{
			m = i;
			break;
		}
	}	           
	for (int i = m; i >= 0; i--)
	{	
		if (s >= a[i])
			{                     
				b[ans++] = a[i];
				s -= a[i];
			}         
	}
	printf("%d\n", ans);
	for (int i = 0; i < ans; i++)
	{
		printf("%d ", b[i]);
	}
	return 0;
}