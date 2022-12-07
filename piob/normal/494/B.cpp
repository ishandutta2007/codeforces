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

void pref_suf(const char *w, int n, int *p) {
    p[0] = 0;
    for(int i=1;i<n;i++) {
        p[i] = p[i-1];
        while(p[i] > 0 && w[i] != w[p[i]]) p[i] = p[p[i]-1];
        if (w[i] == w[p[i]]) p[i]++;
    }
}

int n, m;

int C[100010];
int M[100010];
int P[200010];

char W[200010];
char S[100010];
char T[100010];

int f(PII p, int x){
	return ((LL)p.x * x + p.y) % mod;
}

int d;
PII D[2*128*1024+3];

int get(int a, int b, int x){
	a += d, b += d;
	int r = 0;
	while(a < b){

		if(a&1){
			r = (r + f(D[a], x)) % mod;
			++a;
		}
		if((b&1)==0){
			r = (r + f(D[b], x)) % mod;
			--b;
		}
		a /= 2;
		b /= 2;
	}
	if(a == b){
		r = (r + f(D[a], x)) % mod; 
	}
	return r;
}

void add(int a, PII p){
	a += d;
	while(a){
		D[a] = PII((D[a].x + p.x) % mod, (D[a].y + p.y) % mod);
		a /= 2;
	}
}

int main(){
	scanf("%s%s", S, T);

	m = strlen(S);
	n = strlen(T);

	FWD(i,0,n) W[i] = T[i];

	W[n] = '#';
	FWD(i,0,m) W[n+i+1] = S[i];
	pref_suf(W, n+m+1, P);

	d = 1;
	while(d < m+1) d *= 2;

	int res = 0;

	FWD(i,1,m+1){
		if(P[n+i] == n){
			C[i] = (C[i] + (get(0,i-n,i-n+1))) % mod; // sum C[i-n-k] * (i-n - (i-n-k) + 1)
			C[i] = (C[i] + i-n+1) % mod;
		}else{
			C[i] = C[i-1];
		}
		res = (res + C[i]) % mod;
		//printf("%d %d\n", i, C[i]);
		add(i, PII(C[i], (mod-(LL)C[i]*i%mod) % mod));
	}

	printf("%d\n", res);
	return 0;
}