#include<cstdio>

int n, k, l, b, a[1000000];

int main()
{
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
  	scanf("%d", &a[i]);
  for (int i = k; i < n; i++)
  	if (a[i] != a[k - 1])
  		b = 1;
  if (b == 1)
  {
  	printf("%d\n", -1);
  	return 0;
  }
  else
  {
  	l = 0;
  	for (int i = k - 1; i >= 0; i--)
  		if (a[i] != a[k - 1])
  		{
  			l = i + 1;
  			break;
  		}
  	printf("%d\n", l);
  }
  return 0;
}