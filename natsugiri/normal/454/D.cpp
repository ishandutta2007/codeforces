#include<cstdio>
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

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

int gcd(int x, int y) {
    while (y) {
	x %= y;
	swap(x, y);
    }
    return x;
}
int GCD[111][111];

int N, B[111];
pair<int, int> A[111];
int best;
vector<int> v, best_v;
int sums[111];

// [1, 58]

void update() {
    int sum = 0;
    sum = sums[N-v.size()];
    REP (i, v.size()) sum += abs(A[i+N-v.size()].first - v[i]);
    if (best > sum) {
	best = sum;
	best_v = v;
    }
}

void rec(int x) {
    update();
    if ((int)v.size() == N || x == 59) {
	return;
    }

    bool ok = true;
    REP (i, v.size()) if (GCD[v[i]][x] != 1) {
	ok = false;
	break;
    }
    if (ok) {
	v.push_back(x);
	rec(x+1);
	v.pop_back();
    }
    rec(x+1);
}

int main() {
    REP (i, 111) REP (j, 111) GCD[i][j] = gcd(i, j);
    scanf("%d", &N);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	A[i] = make_pair(x, i);
    }
    sort(A, A+N);
    REP (i, N) sums[i+1] = sums[i] + A[i].first;

    best = 1<<29;

    rec(2);

    REP (i, N) B[i] = 1;
    REP (i, best_v.size()) B[A[i+N-best_v.size()].second] = best_v[i];
    REP (i, N) printf("%d%c", B[i], i+1 == N ? '\n' : ' ');

    return 0;
}