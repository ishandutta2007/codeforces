#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7 + 10;
int x[maxn];
int v[maxn][11];
int p[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	for(int i = 2; i < maxn; i++){
		if(p[i])
			continue;
		for(int j = i; j < maxn; j += i)
			v[j][p[j]++] = i;
	}
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		for(int j = 0; j < p[a]; j++)
			x[v[a][j]]++;
	}
	for(int i = 1; i <= maxn - 10; i++)
		x[i] += x[i - 1];
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		if(l > r or l >= 1e7){
			printf("0\n");
			continue;
		}
		r = min(r, maxn - 10);
		l == min(r, l);
		l --;
		printf("%d\n", x[r] - x[l]);
	}
	return 0;
}