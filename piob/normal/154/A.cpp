#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
typedef long double K;

const K PI = acos((long double)-1);

int n, k, cx, cy, r;
char S[100010];
char T[5], x, y;

int main(){
	scanf("%s", S);
	n = strlen(S);
	scanf("%d", &k);
	FWD(i,0,k){
		scanf("%s", T);
		x = T[0], y = T[1];
		int p = 0, k = 0;
		while(p < n){
			cx = cy = 0;
			while(S[k] == x || S[k] == y){
				if(S[k] == x) ++cx;
				if(S[k] == y) ++cy;
				++k;
			}
			p = ++k;
			r += min(cx, cy);
		}
	}
	printf("%d\n", r);
	return 0;
}