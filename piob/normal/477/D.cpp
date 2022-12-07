#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define x first
#define y second
#define pb push_back
#define mp make_pair
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
const int INF = 1000000010;

int n;
char S[5020];
int L[5010];
int C[5010];
int RV;
PII RM;
int lookup[5010];
int val[5010][15];
int hp[5010][5010];

int H[13][(1<<13)+3];
void kmr() {
	FWD(i,0,n) H[0][i] = S[i]-'0';
	pair<PII,int> T[n];
	FWD(s,0,12){
		int d = (1<<s);
		FWD(i,0,n) T[i] = make_pair(PII(H[s][i], i+d<n?H[s][i+d]:0), i);
		sort(T, T+n);
		d = 0;
		FWD(i,0,n){
			if(i && T[i-1].x != T[i].x) ++d;
			H[s+1][T[i].y] = d;
		}
	}
}

bool eq(PII a, PII b){
	if(a.y-a.x != b.y-b.x) return 0;
	return hp[a.x][a.y] == hp[b.x][b.y];
}

int cmp_d;

bool cmp(PII a, PII b){
	int ha = hp[a.x][a.y];
	int hb = hp[b.x][b.y];
	if(ha == hb) return a.x < b.x;
	return ha < hb;
}

int diff(PII a, PII b){
	if(max(a.y-a.x, b.y-b.x) > 12){
		if(!eq(PII(a.x, a.y-12), PII(b.x, b.y-12))) return INF;
		a.x = a.y-12;
		b.x = b.y-12;
	}
	return val[a.x][a.y-a.x] - val[b.x][b.y-b.x];
}

vector<pair<int,PII> > P;

pair<int,PII> prep(PII p) { return mp(hp[p.x][p.y], p); }

int main(){
	scanf("%s", S);
	n = strlen(S);
	FWD(i,1,n+1){
		int d = 0;
		while((1<<(d+1)) < i) ++d;
		lookup[i] = d;
	}
	FWD(i,0,n){
		val[i][0] = 0;
		FWD(d,1,14) val[i][d] = val[i][d-1]*2 + S[i+d-1] - '0';
	}
	kmr();
	FWD(i,0,n)
		FWD(j,i+1,n+1)
			hp[i][j] = (H[lookup[j-i]][i] << 16) + H[lookup[j-i]][j-(1<<lookup[j-i])];
	FWD(d,1,n+1){
		int m = P.size();
		FWD(i,0,n+1-d)
			if(S[i] == '1')
				P.push_back(prep(PII(i,i+d)));
		sort(P.begin()+m, P.end());
	}
	C[0] = 1;
	FWD(i,1,n+1) L[i] = INF;
	RV = INF;
	for(pair<int,PII> p_ : P){
        PII p = p_.y;
		if(L[p.x] == INF) continue;
		C[p.y] = (C[p.y] + C[p.x]) % mod;
		L[p.y] = min(L[p.y], L[p.x] + 1);
		if(p.y == n){
			if(RV == INF){
				RV = L[n];
				RM = p;
			}else{
				// p + L[n] < RM + RV
				if(diff(p, RM) < RV - L[n]){
					RM = p;
					RV = L[n];
				}
			}
		}
	}
	printf("%d\n", C[n]);
	int r = 0;
	FWD(i,RM.x,RM.y)
		r = (2*r + S[i]-'0') % mod;
	r = (r + RV) % mod;
	printf("%d\n", r);
	return 0;
}