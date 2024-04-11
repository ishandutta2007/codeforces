#include<map>
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

template<class T>
struct Fenwick : vector<T> {
    typedef vector<T> S;
    int N;
    Fenwick(int N_=0): S(N_), N(N_) {}
    void add(int i, T x) {
	for (; i<N; i|=i+1) S::operator[](i) += x;
    }
    inline T sum(int r) {
	T s = 0;
	for (; r; r&=r-1) s += S::operator[](r-1);
	return s;
    }
    T sum(int l, int r) {
	return sum(r) - sum(l);
    }
};

template<class T> vector<int> compress(const vector<T> &v, vector<T> *unq=NULL) {
    int n = v.size();
    vector<pair<T, int> > t(n);
    for (int i=0; i<n; i++) t[i] = make_pair(v[i], i);
    sort(t.begin(), t.end());
    vector<int> r(n);
    int cur = 0;
    for (int i=0, k=0; i<n; i++) {
	if (t[k].first < t[i].first) k = i, cur++;
	r[t[i].second] = cur;
    }
    if (unq) {
	unq->resize(cur+1);
	cur = 0;
	for (int i=0; i<n; i++)
	    if (i == 0 || t[i-1].first < t[i].first)
		(*unq)[cur++] = t[i].first;
    }
    return r;
}

struct Event {
    int t, p, x;
    bool operator<(const Event &y) const {
	return t != y.t ? t < y.t :
	    p < y.p;
    }
};
int N;
int A[100111][4];
VI allX;

void con(map<int, vector<pair<int, int> > > &M) {
    EACH (e, M) {
	vector<pair<int, int> > &v = e->second, w;
	sort(v.begin(), v.end());
	int cur = 0;
	EACH (f, v) {
	    if (f->second == -1) {
		if (cur == 0) w.push_back(make_pair(f->first, -1));
		cur++;
	    } else {
		cur--;
		if (cur == 0) w.push_back(make_pair(f->first, +1));
	    }
	}
	v = w;
    }
}

map<int, vector<pair<int, int> > > Mx, My;

VI unq;
int getX(int x) {
    return lower_bound(unq.begin(), unq.end(), x) - unq.begin();
}

int main() {
    scanf("%d", &N);
    
    REP (i, N) {
	REP (j, 4) scanf("%d", A[i]+j);
	if (A[i][0] > A[i][2]) swap(A[i][0], A[i][2]);
	if (A[i][1] > A[i][3]) swap(A[i][1], A[i][3]);

	allX.push_back(A[i][0]);
	allX.push_back(A[i][2]);
    }

    VI C = compress(allX, &unq);

    REP (i, N) {
	if (A[i][0] == A[i][2]) { // vertical
	    Mx[A[i][0]].push_back(make_pair(A[i][1], -1));
	    Mx[A[i][0]].push_back(make_pair(A[i][3], 1));
	} else {
	    My[A[i][1]].push_back(make_pair(A[i][0], -1));
	    My[A[i][1]].push_back(make_pair(A[i][2], 1));
	}
    }

    con(Mx); con(My);

    LL ans = 0;

    vector<Event> Ex;
    EACH (e, Mx) {
	EACH (f, e->second) {
	    Event x;
	    x.t = f->first;
	    x.p = f->second;
	    x.x = e->first;
	    Ex.push_back(x);
	}
	vector<pair<int, int> > &v = e->second;
	for (int i=0; i<(int)v.size(); i+=2) {
	    ans += v[i+1].first - v[i].first + 1;
	}
    }
    sort(Ex.begin(), Ex.end());

    Fenwick<int> F(C.size());
    int k = 0;
    EACH (e, My) {
	while (k < (int)Ex.size() && Ex[k].t < e->first) {
	    int idx = getX(Ex[k].x);
	    F.add(idx, -Ex[k].p);
	    k++;
	}
	while (k < (int)Ex.size() && Ex[k].t == e->first && Ex[k].p == -1) {
	    int idx = getX(Ex[k].x);
	    F.add(idx, -Ex[k].p);
	    k++;
	}

	vector<pair<int, int> > &v = e->second;
	for (int i=0; i<(int)v.size(); i+=2) {
	    int le = getX(v[i].first);
	    int ri = getX(v[i+1].first);
	    ans += v[i+1].first - v[i].first + 1 - F.sum(le, ri+1);
	}
    }


    printf("%lld\n", ans);
    return 0;
}