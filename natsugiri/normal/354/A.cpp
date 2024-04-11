#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL INF = 1LL<<60;

int N, L, R, QL, QR;
int W[100010];
LL sums[100010];

int main() {

    scanf("%d%d%d%d%d", &N, &L, &R, &QL, &QR);
    for (int i=0; i<N; i++) scanf("%d", W+i);
    for (int i=0; i<N; i++) sums[i+1] = W[i] + sums[i];

    LL ans = INF;
    for (int i=0; i<=N; i++) {
	int le = i, ri = N-i;
	LL tmp = sums[i]*L + (sums[N]-sums[i])*R;
	if (le < ri) tmp += LL(ri - le - 1LL)*QR;
	if (le > ri) tmp += LL(le - ri - 1LL)*QL;

	ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}