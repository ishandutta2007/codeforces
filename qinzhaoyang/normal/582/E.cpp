#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 510 , M = 16 , P = 1000000007;
int add(int x , int y) {return x + y >= P ? x + y - P : x + y;}
int sub(int x , int y) {return x < y ? x - y + P : x - y;}
int mul(int x , int y) {return 1ll * x * y % P;}
void upd(int &x , int y) {x = add(x , y);}

char s[N] , c[N];
int n , m , h[M][5] , fa[N] , p , t , f[N][1 << M];
vector <int> e[N];

int a[1 << M] , b[1 << M];

void OR(int *a , int type) {
	for(int i = 1; i < n; i <<= 1)
		for(int j = 0; j < n; j += (i << 1))
			for(int k = 0; k < i; k++)
				a[i + j + k] = (type == 1 ? add(a[i + j + k] , a[j + k]) : sub(a[i + j + k] , a[j + k]));
}

void AND(int *a , int type) {
	for(int i = 1; i < n; i <<= 1)
		for(int j = 0; j < n; j += (i << 1))
			for(int k = 0; k < i; k++)
				a[j + k] = (type == 1 ? add(a[j + k] , a[i + j + k]) : sub(a[j + k] , a[i + j + k]));
}

void calc(int z , int x , int y , void (*cal)(int* , int)) {
	for(int i = 0; i < n; i++) a[i] = f[x][i];
	for(int i = 0; i < n; i++) b[i] = f[y][i];
	cal(a , 1) , cal(b , 1);
	for(int i = 0; i < n; i++) a[i] = mul(a[i] , b[i]);
	cal(a , -1);
	for(int i = 0; i < n; i++) upd(f[z][i] , a[i]);
}

void dfs(int x) {
	if(e[x].empty()) {
		if(c[x] == '?') {
			for(int i = 0; i < 4; i++) {
				int A = 0;
				for(int j = 0; j < m; j++) A |= h[j][i] << j;
				f[x][A] += 1 , f[x][(n - 1) ^ A] += 1;
			}
		}
		else {
			int i = c[x] - ('a' <= c[x] ? 'a' : 'A') , A = 0;
			for(int j = 0; j < m; j++) A |= h[j][i] << j;
			f[x]['a' <= c[x] ? ((n - 1) ^ A) : A] += 1;
		}
		return;
	}
	dfs(e[x][0]) , dfs(e[x][1]);
	if(c[x] != '&') calc(x , e[x][0] , e[x][1] , OR);
	if(c[x] != '|') calc(x , e[x][0] , e[x][1] , AND);
}

int main() {
	scanf("%s%d" , s + 1 , &m) , n = 1 << m;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < 5; j++)
			scanf("%d" , &h[i][j]);
	p = 1 , t = 1;
	for(int i = 1 , l = strlen(s + 1); i <= l; i++) {
		if(s[i] == '(') e[p].push_back(++t) , fa[t] = p , p = t;
		else if(s[i] == ')') p = fa[p];
		else c[p] = s[i];
	}
	dfs(1); int A = 0;
	for(int i = 0; i < m; i++) A |= h[i][4] << i;
	printf("%d\n" , f[1][A]);
	return 0;
}