#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int x, y, a, b;
int C[110];

int main(){
	scanf("%d %d %d %d", &x, &y, &a, &b);
	int c = 0;
	FWD(i,a,x+1)
		FWD(j,b,min(i,y+1))
			++c;
	printf("%d\n", c);
	FWD(i,a,x+1)
		FWD(j,b,min(i,y+1))
			printf("%d %d\n", i, j);
	return 0;
}