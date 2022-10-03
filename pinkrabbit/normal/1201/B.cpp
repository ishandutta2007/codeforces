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

int N, A[MN];
LL S;

int main() {
	scanf("%d", &N);
	F(i, 1, N) scanf("%d", A + i), S += A[i];
	if (S & 1) return puts("NO"), 0;
	sort(A + 1, A + N + 1);
	if (A[N] + A[N] > S) return puts("NO"), 0;
	return puts("YES"), 0;
}