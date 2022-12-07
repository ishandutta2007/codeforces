#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int n, r;
int x, y, d;

int main(){
	scanf("%d", &n);
	d = 0;
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		if(d == 0){
			y = a;
			d = 1;
		}else if(d == 1){
			x = y;
			y = a;
			d = 2;
		}else{
			if(x+y == a)
				++d;
			else
				d = 2;
			x = y;
			y = a;
		}
		r = max(r, d);
	}
	printf("%d\n", r);
	return 0;
}