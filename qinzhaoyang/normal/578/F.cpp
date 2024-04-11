#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n , m , P;
inline int add(int x , int y) {return x + y >= P ? x + y - P : x + y;}
inline int sub(int x , int y) {return x < y ? x - y + P : x - y;}
inline int mul(int x , int y) {return 1ll * x * y % P;}
inline int Pow(int x , int y) {int ret = 1; while(y){if(y & 1) ret = mul(ret , x); x = mul(x , x) , y >>= 1;} return ret;}

char s[N][N]; int fa[N * N] , id[N][N] , tag[N * N] , a[N << 2][N << 2];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
int con(int x , int y) {if(find(x) != find(y)) fa[fa[x]] = fa[y];}
void E(int x , int y) {
	if(x == y) return;
	a[x][x] = add(a[x][x] , 1) , a[y][y] = add(a[y][y] , 1);
	a[x][y] = sub(a[x][y] , 1) , a[y][x] = sub(a[y][x] , 1);
}

int G(int siz) {
	int ret = 1;
	for(int i = 1; i <= siz; i++) {
		int p = i;
		for(int j = i + 1; j <= siz; j++)
			if(a[p][i] < a[j][i]) p = j;
		if(p != i) swap(a[p] , a[i]) , ret = sub(0 , ret);
		ret = mul(ret , a[i][i]); int inv = Pow(a[i][i] , P - 2);
		for(int j = i + 1; j <= siz; j++) {
			int tmp = mul(a[j][i] , inv);
			for(int k = i; k <= siz; k++)
				a[j][k] = sub(a[j][k] , mul(a[i][k] , tmp));
		}
	}
	return ret;
}

int S(int t) {
	int tot = 0 , cnt = 0;
	for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++)
		if(((i + j) & 1) == t) id[i][j] = ++tot;
	for(int i = 1; i <= tot; i++) fa[i] = i;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
		if(s[i][j] == '/' && ((i + j - 1) & 1) == t)
			con(id[i][j - 1] , id[i - 1][j]);
		if(s[i][j] == '\\' && ((i + j) & 1) == t)
			con(id[i - 1][j - 1] , id[i][j]);
	}
	for(int i = 1; i <= tot; i++)
		if(find(i) == i) tag[i] = ++cnt;
	memset(a , 0 , sizeof a);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
		if(((i + j - 1) & 1) == t && s[i][j] == '*') E(tag[find(id[i - 1][j])] , tag[find(id[i][j - 1])]);
		else if(((i + j) & 1) == t && s[i][j] == '*') E(tag[find(id[i - 1][j - 1])] , tag[find(id[i][j])]);
	}
	return G(cnt - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> P;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> s[i][j];
	cout << add(S(0) , S(1)) << endl;
	return 0;
}