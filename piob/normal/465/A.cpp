#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;
const K eps = 1e-9;

int n;
char buff[110];

int main(){
	scanf("%d%s", &n, buff);
	int i = 0;
	while(buff[i] == '1') ++i;
	printf("%d\n", min(n, i+1));
	return 0;
}