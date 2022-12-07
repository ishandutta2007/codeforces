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

int k;
LL a, b;

int main(){
	scanf("%I64d %I64d %d", &a, &b, &k);
	if(b-a+1 <= 4){
		LL res = a+1;
		int bm;
		FWD(m,1,1<<(b-a+1)){
			if(__builtin_popcount(m) > k)
				continue;
			LL cr = 0;
			FWD(i,0,b-a+1)
				if(m&(1<<i))
					cr ^= (a+i);
			if(cr < res){
				res = cr;
				bm = m;
			}
		}
		printf("%I64d\n", res);
		printf("%d\n", __builtin_popcount(bm));
		FWD(i,0,b-a+1)
			if(bm&(1<<i))
				printf("%I64d ", a+i);
		printf("\n");
		return 0;
	}
	if(k == 1)
		printf("%I64d\n1\n%I64d\n", a, a);
	else if(k == 2)
		printf("1\n2\n%I64d %I64d\n", a+(a&1), a+(a&1)+1);
	else if(k >= 4)
		printf("0\n4\n%I64d %I64d %I64d %I64d\n", a+(a&1), a+(a&1)+1, a+(a&1)+2, a+(a&1)+3);
	else{
		LL x = 1;
		LL y = 2;
		LL z = 3;
		while(z <= b){
			if(x >= a){
				printf("0\n3\n%I64d %I64d %I64d\n", x, y, z);
				return 0;
			}
			x = 2*x + 1;
			y = 2*y + 1;
			z = 2*z;	
		}
		printf("1\n2\n%I64d %I64d\n", a+(a&1), a+(a&1)+1);
	}
	return 0;
}