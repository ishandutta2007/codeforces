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

int n, m;
char P[110];

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,n){
		scanf("%s", P);
		FWD(j,0,m)
			if(P[j] == '.')
				P[j] = ((i+j)&1) ? 'W' : 'B';
		printf("%s\n", P);
	}
	return 0;
}