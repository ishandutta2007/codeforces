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

int a, b, c;

int main(){
	scanf("%d %d %d", &a, &b, &c);
	int x = (a+b-c)/2;
	int y = (b+c-a)/2;
	int z = (c+a-b)/2;
	if(x < 0 || y < 0 || z < 0 || (x+y) != b || (y+z) != c || (x+z) != a)
		printf("Impossible");
	else
		printf("%d %d %d\n", x, y, z);
	return 0;
}