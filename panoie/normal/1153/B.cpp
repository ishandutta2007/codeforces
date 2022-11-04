#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 105;
int n, m, h, a[N], b[N], c[N][N];
int main() {
	scanf("%d%d%d", &n, &m, &h);
	for(int i=1; i<=m; ++i) scanf("%d", b+i);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) scanf("%d", c[i]+j);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
		printf("%d%c", c[i][j]?min(a[i], b[j]):0, " \n"[j==m]);
	}
	return 0;
}