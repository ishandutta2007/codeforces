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

int N, M, Ans;
char str[MN];
int b[MN][5];

int main() {
	scanf("%d%d", &N, &M);
	F(i, 1, N) {
		scanf("%s", str + 1);
		F(j, 1, M) ++b[j][str[j] - 'A'];
	}
	F(i, 1, M) {
		int x;
		scanf("%d", &x);
		Ans += x * max(b[i][0], max(b[i][1], max(b[i][2], max(b[i][3], b[i][4]))));
	}
	printf("%d\n", Ans);
	return 0;
}