#include<cstdio>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)


int N, L, X[1011], B[1011];

double cost(int f, int t, double C) {
    return sqrt(abs(X[t] - X[f] - L)) - B[t]*C;
}

vector<double>len;
vector<int>prev;

double calc(double C) {
    len.assign(N+1, 0);
    prev.assign(N+1, -1);
    for (int i=1; i<=N; i++) {
	int p=0;
	REP (j, i) {
	    if (cost(p, i, C) + len[p] > cost(j, i, C) + len[j]) p = j;
	}
	len[i] = cost(p, i, C) + len[p];
	prev[i] = p;
    }
    return len[N];
}

int main() {
    scanf("%d%d", &N, &L);
    REP (i, N) scanf("%d%d", X+i+1, B+i+1);

    double lo = 0.0, hi = 1e10;
    REP ($, 80) {
	double m = (lo + hi) / 2;
	if (calc(m) < 0) hi = m;
	else lo = m;
    }
    
    vector<int>ans;
    for (int s=N; s>0; s=prev[s]) {
	ans.push_back(s);
    }
    for (int i=ans.size(); i--;) {
	printf("%d%c", ans[i], i==0?'\n':' ');
    }
    return 0;
}