#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, m;
bool W[1010];

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,m){
		int a;
		scanf("%d", &a);
		W[a] = 1;
		scanf("%d", &a);
		W[a] = 1;
	}
	FWD(i,1,n+1)
		if(!W[i]){
			printf("%d\n", n-1);
			FWD(j,1,n+1)
				if(i!=j)
					printf("%d %d\n", i, j);
			return 0;
		}
}