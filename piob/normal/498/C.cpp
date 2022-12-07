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

const int INF = 1000000;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

namespace flow {
	const int N = 1000;
	int n, cap[N][N];   // INPUT
	int flow[N][N];     // OUTPUT

	int edmonds(int s, int t) {
	    int b,e,q[n],p[n],d,FLOW=0;
	    REP(i,n) REP(j,n) flow[i][j]=0;
	    for(;;) {
	        REP(i,n) p[i]=-1;
	        for(q[b=e=0]=s;b<=e;b++)
	            REP(v,n) 
	                if (flow[q[b]][v] < cap[q[b]][v] && p[v]<0)
	                    p[q[++e]=v] = q[b];
	        if (p[t]<0) break;
	        d = cap[p[t]][t] - flow[p[t]][t];
	        for(int i=t;i!=s;i=p[i]) d=min(d,cap[p[i]][i]-flow[p[i]][i]);
	        for(int i=t;i!=s;i=p[i]) {
	            flow[p[i]][i] += d;
	            flow[i][p[i]] -= d;
	        }
	        FLOW += d;
	    }
	    return FLOW;
	}
}

int n, s, t, ps, m;
int A[110];
int P[110];
int Q[110];
vector<int> allp;

int main(){
	scanf("%d", &n);
	scanf("%d", &m);
	s = 0;
	t = n+1;
	flow::n = n+2;
	FWD(i,1,n+1){
		int a;
		scanf("%d", &a);
		A[i] = a;
		for(int d = 2; d*d <= a; ++d){
			if(a % d == 0){
				allp.push_back(d);
				while(a % d == 0)
					a /= d;
			}
		}
		if(a > 1)
			allp.push_back(a);
	}
	FWD(i,0,m){
		scanf("%d %d", &P[i], &Q[i]);
		if(Q[i]&1) swap(P[i], Q[i]);
	}
	sort(allp.begin(), allp.end());
	allp.erase(unique(allp.begin(), allp.end()), allp.end());
	ps = allp.size();
	int res = 0;
	for(int p : allp){
		FWD(i,0,n+2) FWD(j,0,n+2) flow::cap[i][j] = 0;
		FWD(i,0,m) flow::cap[P[i]][Q[i]] = INF;
		FWD(i,1,n+1){
			int c = 0;
			while(A[i] % p == 0){
				++c;
				A[i] /= p;
			}
			if(i&1) flow::cap[s][i] = c;
			else flow::cap[i][t] = c;
		}
		res += flow::edmonds(s,t);
	}
	printf("%d\n", res);
	return 0;
}