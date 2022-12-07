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

int n, d;

struct transfer {
	int add[60];
	int eval(int t){
		return t + add[t % 60];
	}
};

transfer operator+(const transfer &a, const transfer &b){
	transfer c;
	FWD(i,0,60) c.add[i] = a.add[i] + b.add[(a.add[i]+i)%60];
	return c;
}

transfer make_transfer(int p){
	transfer c;
	FWD(i,0,60) c.add[i] = (i % p == 0 ? 2 : 1);
	return c;
}

transfer D[256*1024];

int get(int a, int b){
	vector<transfer*> front, back;
	a += d;
	b += d;
	while(a < b){
		if(a&1){
			front.push_back(&D[a]);
			//printf("f transfer numer %d\n", a);
			++a;
		}
		if((b&1)==0){
			back.push_back(&D[b]);
			//printf("b transfer numer %d\n", b);
			--b;
		}
		a /= 2; b /= 2;
	}
	if(a == b){
		//printf("f transfer numer %d\n", a);
		front.push_back(&D[a]);
	}
	reverse(back.begin(), back.end());
	int x = 0;
	for(transfer* t : front) x = t->eval(x);
	for(transfer* t : back) x = t->eval(x);
	return x;
}

char buff[5];
int main(){
	scanf("%d", &n);
	d = 1;
	while(d < n) d *= 2;
	FWD(i,0,n){
		int a;
		scanf("%d", &a);
		D[d+i] = make_transfer(a);
	}
	BCK(i,d-1,0) D[i] = D[2*i] + D[2*i+1];
	int q;
	scanf("%d", &q);
	FWD(i,0,q){
		int x, y;
		scanf("%s %d %d", buff, &x, &y);
		if(buff[0] == 'A'){
			--x;
			--y;
			printf("%d\n", get(x, y-1));
		}else{
			--x;
			x += d;
			D[x] = make_transfer(y);
			x /= 2;
			while(x){
				D[x] = D[2*x] + D[2*x+1];
				x /= 2;
			}
		}
	}
	return 0;
}