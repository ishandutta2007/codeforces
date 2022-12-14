#include"bits/stdc++.h"
using namespace std;

int n;

vector<int> r;
vector<int> c;
int m;
int ans[200][200];

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		r.push_back(a);
	}
	for (int i = 0; i < m; i++){
		int a;
		scanf("%d", &a);
		c.push_back(a);
	}
	int zz = c.back();
	for (int i = 0; i+1 < n; i++){
		zz ^= r[i];
		ans[i][m - 1] = r[i];
	}
	int z = r.back();
	for (int i = 0; i + 1 < m; i++){
		z ^= c[i];
		ans[n - 1][i] = c[i];
	}
	if (z != zz){
		puts("NO");
		return 0;
	}
	puts("YES");
	ans[n - 1][m - 1] = z;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (j)printf(" ");
			printf("%d", ans[i][j]);
		}
		puts("");
	}
	return 0;
}