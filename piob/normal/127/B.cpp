#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, r, h;
int C[110];

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		++C[a];
	}
	FWD(i,1,101){
		r += C[i] / 4;
		if(C[i]%4 > 1)
			++h;
	}
	r += h/2;
	printf("%d\n", r);
	return 0;
}