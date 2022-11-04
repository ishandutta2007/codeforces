#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char f[100000][51],s[100000][51],temp[51],h[100000][51];
int main()
{
	int n, i, j, k, *p, x, y;
	char enter[1], space[1];
	scanf("%d", &n);
	p = (int*)malloc(n*sizeof(int));
	scanf("%c", &enter[0]);
	for (i = 0; i <= n - 1; i++){
		j = 0;
		k = 0;
		while (1){
			scanf("%c", &f[i][j]);
			j = j + 1;
			if (f[i][j - 1] == ' ')
			{
				f[i][j - 1] = 0;
				break;
			}
		}
		while (1){
			scanf("%c", &s[i][k]);
			k = k + 1;
			if (s[i][k - 1] == '\n')
			{
				s[i][k - 1] = 0;
				break;
			}
		}
		if ((int)strcmp(s[i], f[i]) == 1){
			for (y = 0; y <= 49; y++)
			{
				temp[y] = f[i][y];
				f[i][y] = s[i][y];
				s[i][y] = temp[y];
			}
		}
	}
	for (i = 0; i <= n - 1; i++)scanf("%d", &p[i]);
	for (i = 0; i <= 49; i++)h[p[0] - 1][i] = s[p[0] - 1][i];
	for (i = 1; i <= n - 1; i++){
		if ((int)strcmp(s[p[i]-1], h[p[i - 1]-1]) == 1)
		for (x = 0; x <= 49; x++)
			h[p[i] - 1][x] = s[p[i] - 1][x];
		else for (x = 0; x <= 49; x++)
			h[p[i] - 1][x] = f[p[i] - 1][x];
		if ((int)strcmp(h[p[i - 1] - 1], f[p[i] - 1]) == 1){
			printf("NO");
			break;
		}
	}
	if (i == n)printf("YES");
	return 0;
}