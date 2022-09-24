#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL INF = 1LL<<60;

struct RMQ {
    int n, m;
    vector<LL>data;
    RMQ(int n) :n(n) {
	m=1;
	for (;m<n;) m*=2;
	data=vector<LL>(m*2, INF);
    }
    void update(int p, LL v) {
	p+=m;
	data[p]=v;
	for (;p;) {
	    p/=2;
	    data[p]=min(data[p*2], data[p*2+1]);
	}
    }
    LL minimum(int x, int y) { return minimum(x, y, 1, 0, m); }
    LL minimum(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return INF;
	if (x<=l && r<=y) return data[k];
	return min(minimum(x, y, k*2, l, (l+r)/2), minimum(x, y, k*2+1, (l+r)/2, r));
    }
};

int N, A[100010];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	scanf("%d", A+i);
	A[i]--;
    }

    RMQ rmq(N);
    int ans=0;
    for (int i=0; i<N; i++) {
	int t=-rmq.minimum(0, A[i]);
	if (t<0) t=0;
	rmq.update(A[i], -t-1);
	ans = max(ans, t+1);
    }

    printf("%d\n", ans);

    return 0;
}