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

int gcd(int a, int b){ while(a&&b) a>b?a%=b:b%=a; return a+b; }

int n, d;

struct node {
	int g, v, c;
} D[256*1024+3];

node operator+(node a, node b){
	return node{gcd(a.g, b.g), min(a.v,b.v), a.v==b.v?a.c+b.c:a.v<b.v?a.c:b.c};
}

int get(int a, int b){
	node r = D[a+d];
	a += d+1;
	b += d;
	while(a < b){
		if(a&1){
			r = r + D[a];
			++a;
		}
		if(~b&1){
			r = r + D[b];
			--b;
		}
		a /= 2;
		b /= 2;
	}
	if(a == b) r = r + D[b];
	return (r.g == r.v ? r.c : 0);
}

int main(){
	scanf("%d", &n);
	d = 1; while(d < n) d*=2;
	FWD(i,d,n+d){
		scanf("%d", &D[i].g);
		D[i].v = D[i].g;
		D[i].c = 1;
	}
	BCK(i,d-1,0) D[i] = D[2*i] + D[2*i+1];
	int q;
	scanf("%d", &q);
	FWD(i,0,q){
		int a, b;
		scanf("%d %d", &a, &b);
		--a; --b;
		printf("%d\n", b-a+1-get(a,b));
	}
	return 0;
}