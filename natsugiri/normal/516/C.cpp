#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }
typedef pair<long long, int> T;
const T INF = make_pair(1LL<<60, 1<<29);
const T NINF = make_pair(-(1LL<<60), -(1<<29));

struct RMMQ {
    int n, m;
    vector<T>mini, maxi;
    RMMQ(int n): n(n) {
	m = 1;
	for (;m<n;) m*=2;
	mini = vector<T>(m*2, INF);
	maxi = vector<T>(m*2, NINF);
    }
    RMMQ(const vector<T> &v): n(v.size()) {
	m = 1;
	for (;m<n;) m*=2;
	mini = vector<T>(m*2, INF);
	maxi = vector<T>(m*2, NINF);
	for (int i=0; i<(int)v.size(); i++) {
	    mini[i+m] = maxi[i+m] = v[i];
	}
	for (int i=m; --i;) {
	    mini[i] = min(mini[i*2], mini[i*2+1]);
	    maxi[i] = max(maxi[i*2], maxi[i*2+1]);
	}
    }
    void update(int p, T v) {
	p += m;
	mini[p] = maxi[p] = v;
	for (;p>1;) {
	    p/=2;
	    mini[p] = min(mini[p*2], mini[p*2+1]);
	    maxi[p] = max(maxi[p*2], maxi[p*2+1]);
	}
    }
    T minimum(int x, int y) { return minimum(x, y, 1, 0, m); }
    T minimum(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return INF;
	if (x<=l && r<=y) return mini[k];
	return min(minimum(x, y, k*2, l, (l+r)/2), minimum(x, y, k*2+1, (l+r)/2, r));
    }
    T maximum(int x, int y) { return maximum(x, y, 1, 0, m); }
    T maximum(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return NINF;
	if (x<=l && r<=y) return maxi[k];
	return max(maximum(x, y, k*2, l, (l+r)/2), maximum(x, y, k*2+1, (l+r)/2, r));
    }
};


int N, M;
int H[100011], D[100011];
int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", D+i);
    REP (i, N) scanf("%d", H+i);

    vector<pair<LL, int> > vx, vy;
    LL sum_d = 0;
    REP (i, 2*N) {
	vx.push_back( make_pair(H[i%N]*2LL + sum_d, i) );
	vy.push_back( make_pair(H[i%N]*2LL - sum_d, i) );
	sum_d += D[i%N];
    }

    RMMQ rmqx(vx), rmqy(vy);
    REP ($, M) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	if (a <= b) a += N; // [b+1 .. a-1]

	int c = rmqx.maximum(b+1, a).second;
	LL ans = max(
	    rmqy.maximum(b+1, c).first + rmqx.maximum(c, a).first,
	    rmqy.maximum(b+1, c+1).first + rmqx.maximum(c+1, a).first);
	// cerr << b+1 << " " << c << " " << a << " " << rmqy.maximum(b+1, c).first << " " << rmqx.maximum(c, a).first << "\n";
	// cerr << b+1 << " " << c+1 << " " << a << " " << rmqy.maximum(b+1, c+1).first << " " << rmqx.maximum(c+1, a).first << "\n";

	printf("%lld\n", ans);
    }
	
    return 0;
}