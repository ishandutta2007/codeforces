#include<stack>
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

const pair<int,int> INF = make_pair( 1<<29, -1 );
struct AddMinimum {
    typedef pair<int,int> T;
    T add(const T &x, const T&y) {
	return make_pair(x.first + y.first, x.second);
    }

    int n, m;
    vector<T>all, data;
    AddMinimum(int n=0) :n(n) {
	m=1;
	for (;m<n;) m*=2;
	all=data=vector<T>(m*2, make_pair(0, -1));
	for (int i=0; i<m; i++) data[i+m].second = i;
	for (int i=m; --i; ) data[i] = min(data[i*2], data[i*2+1]);
    }
    void add(int x, int y, int v) { add(x, y, 1, 0, m, make_pair(v, -1)); }
    void add(int x, int y, int k, int l, int r, T v) {
	if (x<=l && r<=y) {
	    all[k] = add(all[k],v);
	    return;
	} else if (x<r && l<y) {
	    add(x, y, k*2, l, (l+r)/2, v);
	    add(x, y, k*2+1, (l+r)/2, r, v);
	    data[k]=min(add(data[k*2],all[k*2]),
			add(data[k*2+1],all[k*2+1]));
	}
    }
    T minimum(int x, int y) { return minimum(x, y, 1, 0, m); }
    T minimum(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return INF;
	if (x<=l && r<=y) return add(data[k],all[k]);
	return add(
	    min(minimum(x, y, k*2, l, (l+r)/2), minimum(x, y, k*2+1, (l+r)/2, r)),
	    all[k]);
    }
};

int N, C;
int A[100011], B[100011];
bool LE[100011];
char buf[99];
vector<int> ML[1000011], MR[1000011];
vector<int> MM;
int L[1000011], R[1000011];
vector<int> ans;

AddMinimum X;
bool rec(int p, int q) {
    if (p == q) {
	ans.push_back(p);
	return true;
    }

    EACH (e, MR[p]) {
	X.add(p+1, *e+1, -1);
	X.add(*e+1, N+2, 1);
	MM.push_back(*e);
    }
    
    // p [p+1..i-1] [i..q]
    // cerr << p << " - " << q << "\n";
    pair<int, int> t = X.minimum(p+1, q+2);
    // cerr << t.first << " " << t.second << "\n";
    if (t.first != 0) return false;
    EACH (e, ML[p]) {
	X.add(p+1, *e+1, -1);
    }
    EACH (e, MM) {
	X.add(*e+1, N+2, -1);
    }
    MM.clear();
    const int i = t.second;
    
    bool tmp = true;
    if (i != p+1) {
	L[p] = p+1;
	tmp = (tmp && rec(p+1, i-1));
    }
    ans.push_back(p);
    if (i != q+1) {
	R[p] = i;
	tmp = (tmp && rec(i, q));
    }
    return tmp;
}


int main() {
    scanf("%d%d", &N, &C);
    X = AddMinimum(N+2);
    REP (i, C) {
	scanf("%d%d%s", A+i, B+i, buf);
	if (A[i] >= B[i]) {
	    puts("IMPOSSIBLE");
	    return 0;
	}
	if (buf[0] == 'L') LE[i] = true;
	if (LE[i]) {
	    ML[A[i]].push_back(B[i]);
	    X.add(A[i]+1, B[i]+1, 1);
	} else {
	    MR[A[i]].push_back(B[i]);
	    X.add(A[i]+1, B[i]+1, 1);
	}
    }


    bool ok = rec(1, N);

    if (!ok) puts("IMPOSSIBLE");
    else {
	// inord();
	REP (i, N) printf("%d%c", ans[i], i+1==N ? '\n':' ');
    }

    cerr << X.minimum(1, N+1).first << "\n";
    return 0;
}