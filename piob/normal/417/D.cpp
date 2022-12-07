#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000007;
const LL INF = 2000000000LL * 2000000000LL;

struct help{
	int c, m, n, p;
	void read(){
		p = 0;
		scanf("%d %d %d", &c, &m, &n);
		FWD(i,0,n){
			int a;
			scanf("%d", &a);
			p |= 1 << (a-1);
		}
	}
};

bool operator<(const help &a, const help &b){
	return a.m < b.m;
}

int n, m, b;
LL dp[(1<<20)+3];
help H[110];
LL res;

int main(){
	scanf("%d %d %d", &n, &m, &b);
	FWD(i,0,n) H[i].read();
	sort(H, H+n);
	res = INF;
	FWD(s,0,1<<m) dp[s] = INF;
	dp[0] = 0;
	FWD(i,0,n){
		int t = H[i].p;
		FWD(s,0,1<<m) dp[s|t] = min(dp[s|t], dp[s] + H[i].c);
		res = min(res, dp[(1<<m)-1] + (LL)H[i].m*b);
	}
	if(res == INF) res = -1;
	cout << res << endl;
	return 0;
}