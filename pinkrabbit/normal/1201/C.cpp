#include <bits/stdc++.h>
using namespace std;

#define F(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define dF(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define F2(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define vF(i, v) for (auto i : V)

typedef long long LL;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MN = 300005;
const int MM = 600005;
const int Inf = 0x3f3f3f3f;
const LL Infll = 0x3f3f3f3f3f3f3f3f;

int N, M, K;
int A[MN];
LL S;

int main() {
	scanf("%d%d", &N, &K), M = (N + 1) / 2;
	F(i, 1, N) scanf("%d", A + i);
	sort(A + 1, A + N + 1);
	int j = M;
	S = A[M];
	while (j < N && (LL)(j - M + 2) * A[j + 1] - S - A[j + 1] <= K) S += A[++j];
	K -= (LL)(j - M + 1) * A[j] - S;
	printf("%d\n", A[j] + K / (j - M + 1));
	return 0;
}