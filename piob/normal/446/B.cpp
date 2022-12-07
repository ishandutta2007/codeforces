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
typedef pair<LL, int> PLI;
typedef double K;
typedef vector<int> VI;

int dx[] = {0,0,-1,1}; //1,1,-1,1};
int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const int MAXN = 1010;
const int MAXK = 1000010;

int n, m, k, p;
LL R[MAXN];
LL C[MAXN];
priority_queue<LL> qr, qc;
LL WR[MAXK];
LL WC[MAXK];
LL res;

int main(){
	res = 1e9;
	res = -res*res;
	scanf("%d %d %d %d", &n, &m, &k, &p);
	FWD(i,0,n)
		FWD(j,0,m){
			int a;
			scanf("%d", &a);
			R[i] += a;
			C[j] += a;
		}
	FWD(i,0,n) qr.push(R[i]);
	FWD(j,0,m) qc.push(C[j]);
	FWD(z,1,k+1){
		LL s;
		
		s = qr.top();
		qr.pop();
		WR[z] = WR[z-1] + s;
		qr.push(s-m*p);
	
		s = qc.top();		
		qc.pop();
		WC[z] = WC[z-1] + s;
		qc.push(s-n*p);
	}
	
	FWD(i,0,k+1){
		res = max(res, WR[i] + WC[k-i] - (LL)i*(k-i)*p);
	}
	
	cout << res << endl;
	return 0;
}