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
typedef pair<int, int> PII;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n;
LL m;
LL t;
int P[53];
int p, k;

int main(){
	cin >> n >> m;
	p = 0;
	k = n-1;
	--m;
	t = 1;
	FWD(i,0,n-1) t *= 2;
	FWD(i,1,n+1){
		if(m < t/2){
			P[p++] = i;
		}else{
			P[k--] = i;
			m -= t/2;
		}
		t /= 2;
	}
	FWD(i,0,n) printf("%d ", P[i]); printf("\n");
	return 0;
}