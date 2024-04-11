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
int sx, sy, tx, ty;

bool side(int a, int b, int c, int x, int y){
	return (LL)a*x + (LL)b*y + (LL)c < 0LL;
}

int main(){
	scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
	scanf("%d", &n);
	int k = 0;
	FWD(i,0,n){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(side(a,b,c,sx,sy) != side(a,b,c,tx,ty))
			++k;
	}
	printf("%d\n", k);
	return 0;
}