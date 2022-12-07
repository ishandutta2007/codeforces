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

const int INF = 1000*1000*1000;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int n, m, s, t, r, u, v;
char M[1010][1010];
bool P[1010][1010];
int S[1010][1010];

void loc_st(){
	FWD(i,1,n+1) FWD(j,1,m+1) if(M[i][j] == 'X'){
		u = i;
		v = j;
	}
	FWD(i,1,n+1) FWD(j,1,m+1) if(M[i][j] == 'X'){
		s = i;
		t = j;
		return;
	}
}

int ver(int h, int w){
	if(h == 0 || w == 0)
		return -1;
	FWD(i,1,n+1)
		FWD(j,1,m+1)
			if(i+h <= n+1 && j+w <= m+1)
				P[i][j] = (S[i+h-1][j+w-1] - S[i-1][j+w-1] - S[i+h-1][j-1] + S[i-1][j-1] == h*w); else P[i][j] = 0;
	if(!P[s][t]){
		return -1;
	}
	int ar = w*h;
	for(;;){
		P[s][t] = 0;
		if(P[s+1][t]){
			ar += w;
			++s;
		}else if(P[s][t+1]){
			ar += h;
			++t;
		}else
			break;
	}
	FWD(i,1,n+1)
		FWD(j,1,m+1)
			if(P[i][j]){
				return -1;
			}
	if(ar == S[n][m])
		return w*h;
	return -1;
}

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,n+2) FWD(j,0,m+2) M[i][j] = '.';
	FWD(i,1,n+1) scanf("%s", M[i]+1);
	FWD(i,1,n+1)
		FWD(j,1,m+1)
			S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + (M[i][j] == 'X' ? 1 : 0);
	loc_st();
	if(S[n][m] == S[u][v] - S[u][t-1] - S[s-1][v] + S[s-1][t-1] && S[n][m] == (u-s+1)*(v-t+1)){
		printf("%d\n", min(u-s+1, v-t+1));
		return 0;
	}
	int res = -1;
	int h = 0;
	int w = 0;
	while(M[s+h][t] == 'X') ++h;
	int a = 0;
	int b = 0;
	while(M[s][t+a] == 'X') ++a;
	while(M[s+h][t+b] == '.') ++b;
	res = ver(h, abs(a-b));
	
	loc_st();

	h = 0;
	w = 0;
	a = 0;
	b = 0;

	while(M[s][t+w] == 'X') ++w;
	while(M[s+a][t] == 'X') ++a;
	while(M[s+b][t+w] == '.') ++b;
	int pos = ver(abs(a-b), w);
	if(res == -1) res = pos;
	if(pos != -1)
		res = min(res, pos);
	printf("%d\n", res);
	return 0;
}