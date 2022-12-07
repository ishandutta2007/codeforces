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

int n, r;

bool ap(int x){
	int c = 0;
	FWD(i,2,x+1){
		if(x%i==0){
			++c;
			while(x%i==0)
				x /= i;
		}
	}
	return c==2;
}

int main(){
	scanf("%d", &n);
	FWD(i,1,n+1){
		if(ap(i))
			++r;
	}
	printf("%d\n", r);
	return 0;
}