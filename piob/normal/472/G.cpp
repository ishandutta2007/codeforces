#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define re real()
#define im imag()

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
typedef double K;
typedef vector<int> VI;

const int mask = (1<<16)-1;

LL A[64][200000/64+3];
LL B[64][200000/64+3];
char buff[200010];

int lookup[(1<<16)+3];

int popcount(LL x){
	return lookup[x&mask] + lookup[(x>>16)&mask] + lookup[(x>>32)&mask] + lookup[(x>>48)&mask];
}

int n;

int main(){
	FWD(i,1,1<<16) lookup[i] = lookup[i&(i-1)] + 1;
	scanf("%s", buff);
	n = strlen(buff);
	FWD(i,0,n)
		if(buff[i] == '1')
			FWD(r,0,min(64,i+1))
				A[r][(i-r)/64] += 1LL << ((i-r)%64);
	scanf("%s", buff);
	n = strlen(buff);
	FWD(i,0,n)
		if(buff[i] == '1')
			FWD(r,0,min(64,i+1))
				B[r][(i-r)/64] += 1LL << ((i-r)%64);
	int q;
	scanf("%d", &q);
	FWD(_i,0,q){
		int a, b, c, r = 0;
		scanf("%d %d %d", &a, &b, &c);
		int ar = a % 64; a /= 64;
		int br = b % 64; b /= 64;
		FWD(i,0,c/64) r += popcount(A[ar][a+i]^B[br][b+i]);
		r += popcount((A[ar][a+c/64]^B[br][b+c/64])&((1LL<<(c%64))-1));
		printf("%d\n", r);
	}
	return 0;
}