#include<cstdio>

int n, m, k, a[2000][2000], x, y, t, p[2000], q[2000];
char c, ch;

int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
  	for (int j = 1; j <= m; j++)
  	{
  		if (i == n && j == m)
  			break;
  		scanf("%d", &a[i][j]);
  	}
  scanf("%d\n", &a[n][m]);
  for (int i = 1; i <= 1500; i++)
  {
  	p[i] = i;
  	q[i] = i;
  }
  for (int i = 0; i < k; i++)
  {
  	scanf("%c%d%d\n", &c, &x, &y);
  	if (c == 'c')
  	{
  		t = p[x]; 
  		p[x] = p[y];
  		p[y] = t;
  	} 
  	if (c == 'r')
  	{
  		t = q[x]; 
  		q[x] = q[y];
  		q[y] = t;
  	}
  	if (c == 'g')
  		printf("%d\n", a[q[x]][p[y]]);
  
  }
	return 0;
}