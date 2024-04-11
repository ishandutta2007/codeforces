#include <list>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <functional>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

const int N = 100;
const ll MOD = 1000000007;

struct Matrix {
	ll a[N][N];
	Matrix(ll x=0) : a{{0}} { if (x) FOR(i,0,N) a[i][i] = x; }
	ll* operator[](size_t i) { return a[i]; }
	const ll* operator[](size_t i) const { return a[i]; }
};

Matrix operator+(Matrix A, Matrix B) {
	Matrix R;
	FOR(i, 0, N) FOR(j, 0, N) {
		R[i][j] = (A[i][j] + B[i][j]) % MOD;
	}
	return R;
}

Matrix operator*(Matrix A, Matrix B) {
	Matrix R;
	FOR(i, 0, N) FOR(j, 0, N) FOR(k, 0, N) {
		R[i][j] = (R[i][j] + A[i][k] * B[k][j]) % MOD;
	}
	return R;
}

Matrix pow_sum(Matrix A, ll k) {
	Matrix R, B(1);
	int digs = 0;
	while ((1LL << digs) <= k) digs++;
	while (digs--) {
		R = R + B*R;
		B = B*B;
		if (k & (1 << digs)) {
			R = R + B;
			B = B * A;
		}
	}
	return R;
}

int main() {
	ios_base::sync_with_stdio(false);

	ll n, x; cin >> n >> x;
	Matrix A;
	FOR(i,0,n) {
		ll d; cin >> d;
		A[0][d-1]++;
	}
	FOR(i,1,N) A[i][i-1] = 1;

	Matrix B = pow_sum(A,x+1);	

/*
	FOR(i,0,N) {
		FOR(j,0,N) cerr << B[i][j] << " ";
		cerr << endl;
	}

*/
	cout << B[0][0] << endl;
}