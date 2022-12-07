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
typedef tuple<int, int, int> III;

const int mod = 1000000007;
const int INF = 1000000000;

int n, r;

int sim(int a, int b){
	int last = -1;
	int errs = 0;
	int k = 0;
	while(a && b){
		if(a>=b){
			if(last == 0) ++errs;
			last = 0;
			a -= b;
		}else{
			if(last == 1) ++errs;
			last = 1;
			b -= a;
		}
		++k;
	}
	if(a != 0 || b != 1 || k != n) return INF;
	return errs;
}

void wrt(int a, int b){
	char buff[n+1];
	buff[n] = 0;
	while(n){
		if(a>=b){
			buff[--n] = 'T';
			a -= b;
		}else{
			buff[--n] = 'B';
			b -= a;
		}
	}
	printf("%s\n", buff);
}

int main(){
	scanf("%d %d", &n, &r);
	int w = INF, k = -1;
	FWD(i,1,r+1){
		int c = sim(r, i);
		if(c < w){
			w = c;
			k = i;
		}
		c = sim(i, r);
		if(c < w){
			w = c;
			k = -i;
		}
	}
	if(w == INF)
		printf("IMPOSSIBLE\n");
	else{
		printf("%d\n", w);
		if(k > 0)
			wrt(r, k);
		else
			wrt(-k, r);
	}
	return 0;
}