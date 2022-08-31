#include<bits/stdc++.h>
using namespace std;

typedef unsigned int T;

T C(T a, T b) {
	assert(a >= b && b >= 0);
	vector<T> w;
	for(T i = 0; i < b; ++i)
		w.push_back(a - i);
	for(T i = 1; i <= b; ++i) {
		T x = i;
		for(T & y : w) {
			T g = __gcd(x, y);
			x /= g;
			y /= g;
		}
		assert(x == 1);
	}
	T ans = 1;
	for(T x : w) ans *= x;
	return ans;
}

const T MAX_P = 132;
const T MAX_Q = 2000 * 1000 + 5;
const T magic = 1024 * 16;

struct M {
	T t[MAX_P][MAX_P];
	T p;
	M operator * (M other) {
		M ans;
		ans.p = p;
		#define FOR(i) for(T i = 0; i <= p; ++i)
		FOR(i) FOR(j) ans.t[i][j] = 0;
		FOR(i) FOR(j) FOR(k)
			ans.t[i][k] += t[i][j] * other.t[j][k];
		return ans;
	}
};


M matrices[MAX_Q / magic + 1];
T dp[magic][MAX_P], memo_C[MAX_P][MAX_P];

int main() {
    ios_base :: sync_with_stdio(false);
	T n, p, q;
	cin >> n >> p >> q;
	p = min(p, n - 1); // we allow at most n-1 bears to go to sleep
	
	for(T beds = 0; beds <= p; ++beds)
		for(T i = 0; i <= beds; ++i)
			memo_C[beds][i] = C(n-(p-beds), i);
	
	// compute matrices
	
	for(T i = 0; i <= p; ++i)
		matrices[0].t[i][i] = 1;
	
	M & basic = matrices[1];
	basic.p = p;
	
	for(T beds = 0; beds <= p; ++beds)
		for(T i = 0; i <= beds; ++i)
			basic.t[beds-i][beds] = memo_C[beds][i];
	
	for(T i = 1; i < magic; i *= 2)
		basic = basic * basic;
	
	for(T i = 2; i <= q / magic; ++i)
		matrices[i] = matrices[1] * matrices[i-1];
	
	// compute first vectors
	
	for(T beds = 0; beds <= p; ++beds)
		dp[0][beds] = 1;
	
	for(T day = 1; day < magic; ++day)
		for(T beds = 0; beds <= p; ++beds)
			for(T i = 0; i <= beds; ++i) {
				T & x = dp[day][beds];
				x += dp[day-1][beds-i] * memo_C[beds][i];
			}
	T hashed;
	for(T i = 1; i <= q; ++i) {
		T i_dp = i % magic;
		T i_matr = i / magic;
		T ans = 0;
		for(T beds = 0; beds <= p; ++beds)
			ans += dp[i_dp][beds] * matrices[i_matr].t[beds][p];
		hashed ^= i * ans;
	}
	cout << hashed << "\n";
	return 0;
}