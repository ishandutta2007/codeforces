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

const int mod = 1000000007;

char buff[100010];

LL powt(LL a, LL b){
	LL r = 1;
	while(b){
		if(b&1){
			r = (r * a) % mod;
		}
		a = (a * a) % mod;
		b /= 2;
	}
	return r;
}

int m;
string start;
LL width[10];
LL val[10];
string query[100010];

void calculate_val(const char * str, int digit){
	int n = strlen(str);
	LL r = 0, p = 1, w = 0;
	BCK(i,n-1,-1){
		r = (r + val[str[i]-'0'] * p) % mod;
		p = (p * powt(10, width[str[i]-'0'])) % mod;
		w = (w + width[str[i]-'0']) % (mod-1);
	}
	//printf("%d %lld %lld\n", digit, w, r);
	width[digit] = w;
	val[digit] = r;
}

int main(){
	scanf("%s", buff);
	start = string(buff);
	scanf("%d", &m);
	FWD(i,0,m){
		scanf("%s", buff);
		query[i] = string(buff);
	}
	FWD(i,0,10){val[i] = i; width[i] = 1;}
	BCK(i,m-1,-1){
		calculate_val(query[i].data()+3, query[i][0]-'0');
	}
	calculate_val(start.data(), 0);
	printf("%d\n", (int)val[0]);
	return 0;
}