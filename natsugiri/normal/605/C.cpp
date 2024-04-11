#include<cmath>
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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

const double INF = 1e12;
const double EPS = 1e-8;
pair<double, double> solve(double a1, double b1, double r1, double a2, double b2, double r2) {
    b1 /= a1; r1 /= a1;
    b2 /= a2; r2 /= a2;

    if (abs(b1 - b2) < EPS) return make_pair(INF, INF);
    double t = (r1-r2)/(b1-b2);
    double s = r1 - t * b1;
    return make_pair(max(0.0, s), max(0.0, t));
}

bool check(const pair<LL, LL> &a, const pair<LL, LL> &b, const pair<LL, LL> &c) {
    return (b.second - a.second) * (c.first - a.first) <= (c.second - a.second) * (b.first - a.first);
}

int N, P, Q;
pair<LL, LL> A[100111];
vector<pair<int, int> > B;

int main() {
    scanf("%d%d%d", &N, &P, &Q);
    REP (i, N) {
	int x, y;
	scanf("%d%d", &x, &y);
	A[i] = make_pair(x, y);
    }
    sort(A, A+N);
    
    B.push_back(A[0]);

    for (int i=1; i<N; i++) {
	while (B.size() && B.back().second <= A[i].second)
	    B.pop_back();

	while (B.size() >= 2u && check(B[B.size()-2], B.back(), A[i]))
	    B.pop_back();

	B.push_back(A[i]);
    }

    double ans = INF;
    REP (i, B.size()) {
	double guess = max( (double)P / B[i].first,
			    (double)Q / B[i].second );
	amin(ans, guess);
    }
    REP (i, (int)B.size()-1) {
	pair<double, double> g = solve(B[i].first, B[i+1].first, P,
				       B[i].second, B[i+1].second, Q);
	amin(ans, g.first + g.second);
    }

    printf("%.12f\n", ans);
    
    return 0;
}