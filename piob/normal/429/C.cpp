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

const int mod = 1000000009;
const LL INF = 2000000000LL * 2000000000LL;

int n;
int c[27], d;
int sum[(1<<13)+3];

bool check(int roots, int lft, int k){
	//printf("test %d %d %d\n", roots, lft, k);
	if(roots == 0) return lft == 0 && k == 0;
	int r = -1;
	FWD(i,0,n) if(roots&(1<<i)){ r = i; break; }
	roots -= (1<<r);
	FWD(s,0,(1<<n)) if((lft|s) == lft){
		if(c[r] >= 1+sum[s] && c[r] <= 1+sum[s]+k){
			//printf("rect %d %d %d\n", roots, lft, k);
			//printf("	%d %d\n", s, sum[s]);
			if(__builtin_popcount(s) + (c[r]-1-sum[s]) >= 2)
				if(check(roots+s, lft-s, k-(c[r]-1-sum[s])))
					return 1;
		}
	}
	//printf("nope %d %d %d\n", roots, lft, k);
	return 0;
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		if(a == 1){
			++d;
			--n;
			--i;
		}else
			c[i] = a;
	}
	if(d <= n){
		printf("NO\n");
		return 0;
	}
	sort(c, c+n, greater<int>());
	FWD(i,1,1<<n)
		FWD(j,0,n)
			if(i&(1<<j)){
				sum[i] = sum[i-(1<<j)] + c[j];
				break;
			}
	if((n == 0 && d == 1) || check(1, (1<<n)-2, d))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}