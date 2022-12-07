#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;

int n, k;
PII R[100010];
bool collision;

void zip(int a){
	if(R[a].x != a){
		zip(R[a].x);
		R[a].y += R[R[a].x].y;
		R[a].x = R[R[a].x].x;
	}
}

void merge(int a, int b, int d){
	zip(a);
	zip(b);
	if(R[a].x == R[b].x){
		if((R[a].y + d - R[b].y)%2 != 0)
			collision = 1;
	}else{
		d -= R[b].y;
		b = R[b].x;
		R[b].x = a;
		R[b].y = d;
	}
}

int main(){
	scanf("%d %d", &n, &k);
	FWD(i,0,n+2) R[i] = PII(i,0);
	FWD(i,0,k){
		int x, y;
		char z[3];
		scanf("%d %d %s", &x, &y, z);
		--x; --y;
		int a = y-x;
		if(a<0) a = -a;
		int b = y+x;
		if(b>=n) b=2*(n-1)-b;
		merge(a,b+2,z[0]=='o');
	}
	if(collision){
		printf("0\n");
	}else{
		LL r = (mod+1)/2;
		r = r*r % mod;
		FWD(i,0,n+2) if(R[i].x == i) r = 2*r % mod;
		printf("%d\n", (int)r);
	}
	return 0;
}