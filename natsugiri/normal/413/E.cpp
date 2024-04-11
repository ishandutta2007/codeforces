#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

typedef long long LL;
struct RMQ {
    typedef vector<int> T; // 00:uu, 01:ud, 10:du, 11:dd
    static const int INF = 1<<29;
    int n, m;
    vector<T> data;
    T calc(const T&a, const T&b) {
	if (a[0] == -INF) return b;
	if (b[0] == -INF) return a;
	T ret(4, INF);
	for (int j=0; j<4; j++) {
	    int p = 2&j, q = 1&j;
	    ret[j] = min(INF, min(a[p] + b[q], a[p+1] + b[2+q]) + 1 );
	}
	return ret;
    }
    RMQ(string S[2]) :n(S[0].size()) {
	m=1;
	for (;m<n;) m*=2;
	data=vector<T>(m*2, T(4, INF));

	for (int i=0; i<n; i++) {
	    int j=m+i;
	    if (S[0][i] == '.') data[j][0] = 0;
	    if (S[1][i] == '.') data[j][3] = 0;
	    if (S[0][i] == '.' && S[1][i] == '.') data[j][1] = data[j][2] = 1;
	}
	for (int i=m; --i;) data[i] = calc(data[i*2], data[i*2+1]);
	// for (int i=0; i<2*m; i++) {
	//     printf("%d : %d %d %d %d \n", i, data[i][0], data[i][1], data[i][2], data[i][3]);
	// }
    }
    T minimum(int x, int y) { return minimum(x, y, 1, 0, m); }
    T minimum(int x, int y, int k, int l, int r) {
    	if (r<=x || y<=l) return T(4, -INF);
    	if (x<=l && r<=y) return data[k];
	return calc(minimum(x, y, k*2, l, (l+r)/2),minimum(x, y, k*2+1, (l+r)/2, r));
    }
};
const int RMQ::INF;

int main() {
    int N, M;
    string S[2];
    scanf("%d%d", &N, &M);
    cin >> S[0] >> S[1];

    RMQ rmq(S);
    for (;M--;) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	if (a%N > b%N) swap(a, b);
	RMQ::T v = rmq.minimum(a%N, b%N+1);

	// printf("%d %d : ", a, b);
	// for (int i=0; i<4; i++) printf("%d ", v[i]);
	// puts("");

	int k = 0;
	if (b >= N) k += 1;
	if (a >= N) k += 2;
	int ans = v[k];
	if (ans == RMQ::INF) ans = -1;
	printf("%d\n", ans);

    }
    return 0;
}