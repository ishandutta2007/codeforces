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

int mod = 1000000007;

int main(){
	int x, y, n;
	scanf("%d %d %d", &x, &y, &n);
	int r;
	if(n%6 == 0) r = x-y;
	if(n%6 == 1) r = x;
	if(n%6 == 2) r = y;
	if(n%6 == 3) r = y-x;
	if(n%6 == 4) r = -x;
	if(n%6 == 5) r = -y;
	printf("%d\n", (r%mod+mod)%mod);
	return 0;
}