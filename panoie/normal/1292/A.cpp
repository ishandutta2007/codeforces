#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, q, ans, a[2][N];
int main() {
	scanf("%d%d", &n, &q);
	for(int i=1; i<=q; ++i){
		int x, y;
		scanf("%d%d", &x, &y), --x;
		ans-=a[x][y] && a[x^1][y];
		ans-=a[x][y] && a[x^1][y-1];
		ans-=a[x][y] && a[x^1][y+1];
		a[x][y]^=1;
		ans+=a[x][y] && a[x^1][y];
		ans+=a[x][y] && a[x^1][y-1];
		ans+=a[x][y] && a[x^1][y+1];
		puts(ans?"No":"Yes");
	}
	return 0;
}