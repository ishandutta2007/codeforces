#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int MAXN = 100010;
const int MAXV = 2000010;

int y, n, k;

int main(){
	scanf("%d %d %d", &y, &k, &n);
	for(int s=y+(k-y%k); s<=n; s+=k)
		printf("%d ", s-y);
	if(y+(k-y%k)>n) printf("-1");
	printf("\n");
	return 0;
}