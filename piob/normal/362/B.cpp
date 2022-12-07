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
int M[3010];

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,m)
		scanf("%d", &M[i]);
	sort(M, M+m);
	if(M[m-1] == n || M[0] == 1){
		printf("NO\n");
		return 0;
	}
	FWD(i,0,m-2)
		if(M[i+1] == M[i]+1 && M[i+2] == M[i]+2){
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}