#include<cassert>
//#include<unordered_map>
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
#define eprintf(s...)  fprintf(stderr, s)

#ifdef LOCAL
#define Flld "%lld"
#else
#define Flld "%I64d"
#endif

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

// typedef vector<LL> Arr;
// typedef vector<Arr> Mat;

struct Arr {
    LL a[2];
    Arr() {
	a[0] = a[1] = 0;
    }
    int size() { return 2; }
    LL& operator[](int i) { return a[i]; }
};

struct Mat {
    LL a[2][2];
    Mat() {
	memset(a, 0, sizeof a);
    }
    int size() { return 2; }
    LL * operator[](int i) { return a[i]; }
};

Mat identity(int n) {
    Mat r = Mat();
    for (int i=0; i<n; i++) r[i][i] = 1;
    return r;
}

Mat id2;
LL MOD;
Mat mulMatMod(const Mat&a, const Mat&b) {
    int m=2, n = 2;
    Mat r = Mat();
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++) {
	    r[i][j] = (a.a[i][0] * b.a[0][j] + a.a[i][1] * b.a[1][j]) % MOD;
	}
//            for (int k=0; k<p; k++)
//                r[i][k] = (r[i][k]+a[i][j]*b[j][k])%mod;
    return r;
}

Mat powMatMod(Mat a, LL b) {
    Mat r = identity(a.size());
    for (;b; b>>=1) {
	if (b&1) r = mulMatMod(r, a);
	a = mulMatMod(a, a);
    }
    return r;
}

Arr mulMatArrMod(const Mat&a, const Arr&x) {
    int m=2, n = 2;
    Arr r = Arr();
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            r[i] = (r[i]+a.a[i][j]*x.a[j]) % MOD;
    return r;
}
int N, M;
LL K, P, S[50011];
pair<LL, LL> J[50011];
Mat data[140000];
struct SegmentTree {
    int n, m;
    
    SegmentTree() {}
    SegmentTree(int n) :n(n) {
	m=1;
	for (;m<n;) m*=2;
	//data = vector<Mat>(m*2, Mat(2, Arr(2)));
	REP (i, n) {
	    data[i+m] = Mat();
	    data[i+m] [0][0] = S[(i+1)%n];
	    data[i+m] [0][1] = S[i];
	    data[i+m] [1][0] = 1;
	    data[i+m] [1][1] = 0;
	}
	for (int i=n; i<m; i++) data[i+m] = id2;
	for (int i=m; --i; ) {
	    data[i] = mulMatMod(data[2*i+1], data[2*i]);
	}
    }
    Mat query(int x, int y) { return query(x, y, 1, 0, m); }
    Mat query(int x, int y, int k, int l, int r) {
	if (r<=x || y<=l) return id2;
	if (x<=l && r<=y) return data[k];
	return mulMatMod(query(x, y, k*2+1, (l+r)/2, r), query(x, y, k*2, l, (l+r)/2));
    }
};

// void printMat(Mat m) {
//     REP (i, m.size()) {
// 	putchar('{');
// 	REP (j, m[0].size()) printf("%lld ", m[i][j]);
// 	putchar('}');
//     }
// }

SegmentTree st;

Mat seg(LL l, LL r) {
    if (l / N == (r-1) / N) {
	return st.query(l % N, (r-1) % N + 1);
    }
    // LL t = (r-1) % N + 1 + N * ((r-1)/N - l/N-1) + (N-l%N);
    // assert(t == r-l);
    // assert(st.data[1] == st.query(0, N));

    return 
	mulMatMod(
		mulMatMod(
		    st.query(0, (r-1) % N + 1),
		    powMatMod(st.query(0, st.m), (r-1)/N - l/N - 1)),
		st.query(l % N, N));
}

LL nextj(LL i) {
    static int cur = 0;
    while (cur < M && J[cur].first < i) cur++;
    if (cur == M) return K;
    return J[cur].first;
}
LL ss(LL i) {
    static int cur = 1;
    while (cur < M && J[cur].first <= i) cur++;
    for (int p=max(cur-3, 0); p<cur; p++) if (J[p].first == i) return J[p].second;
    return S[i%N];
}

int main() {
    id2 = identity(2);
    scanf(Flld Flld, &K, &P);
    scanf("%d", &N);
    REP (i, N) scanf(Flld, S+i);
    scanf("%d", &M);
    REP (i, M) scanf(Flld Flld, &J[i].first, &J[i].second);

    if (0) {
	srand(5);
	N = 50000;
	M = 50000;
	K = 1000000000000000000LL;
	P = 1000000007;
	REP (i, N) S[i] = rand() % 1000000000;
	REP (i, M) {
	    do {
		J[i].first = rand() % K;
	    } while (J[i].first < N);
	    J[i].second = rand() % 100000000;
	}
    }

    MOD = P;
    REP (i, N) S[i] %= P;
    REP (i, M) J[i].second %= P;

    J[M].first = K;
    J[M].second = 0;
    M++;
    sort(J, J+M);
    st = SegmentTree(N);
//    printMat(st.query(0, 1));
//    putchar('\n');

    LL i = 0;
    Arr f= Arr();
    map<LL, LL> F;
    f[0] = 1; f[1] = 0;
    F[0] = 0; F[1] = 1;
    while (i < K) {
	LL j = nextj(i);
	if (i+1 < j) {
	    f = mulMatArrMod(seg(i, j-1), f);;
	    F[j] = f[0];
	    F[j-1] = f[1];
	} else if (i + 1 == j) {
	    F[j] = f[0];
	} else if (i == K) {
	    F[K] = f[1];
	    break;
	}
	f[1] = F[j+1] = (F[j] * ss(j) + F[j-1] * ss(j-1)) % P;
	f[0] = F[j+2] = (F[j+1] * ss(j+1) + F[j] * ss(j)) % P;
	i = j+1;
    }

//    assert(F.count(K));
//    if (F.count(K) == 0) {
//	F[K] = F[K-1] * ss(K-1) + F[K-2] * ss(K-2);
//    }
    LL ans = F[K];
    ans = (ans % P + P) % P;

    printf("%d\n", (int)ans);

    return 0;
}