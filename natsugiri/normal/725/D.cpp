#include<queue>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

int N;
LL T, W;

struct Data {
    LL t, w;
    Data(){}
    Data(LL t_, LL w_) : t(t_), w(w_) {}
};
struct ByDiff {
    bool operator()(const Data &x, const Data &y) const {
	return (x.w - x.t) > (y.w - y.t);
    }
};
struct ByBaloon {
    bool operator()(const Data &x, const Data &y) const {
	return x.t < y.t;
    }
};
priority_queue<Data, vector<Data>, ByDiff> D;
priority_queue<Data, vector<Data>, ByBaloon> B;

int main() {

    scanf("%d", &N);
    REP (i, N) {
	LL t, w;
	scanf("%lld%lld", &t, &w);
	if (i == 0) {
	    T = t;
	    W = w;
	} else {
	    if (t > T) {
		D.push(Data(t, w));
	    } else {
		B.push(Data(t, w));
	    }
	}
    }

    int ans = D.size();
    while (!D.empty()) {
	LL cost = D.top().w - D.top().t + 1;
	if (cost <= T) {
	    D.pop();
	    T -= cost;
	    while (!B.empty() && B.top().t > T) {
		D.push(B.top()); B.pop();
	    }

	    amin(ans, (int)D.size());
	} else {
	    break;
	}
    }

    printf("%d\n", ans + 1);
    return 0;
}