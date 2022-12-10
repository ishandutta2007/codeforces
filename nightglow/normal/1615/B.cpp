#include <bits/stdc++.h>

#define N 500005
#define M 20

#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

int bit[M][N];

void pre()
{
	for (int i = 0; i < M; ++i)
		for (int j = 1; j < N; ++j)
			bit[i][j] = bit[i][j - 1] + ((j >> i) & 1);
}

void Main()
{
	int l, r, ans;
	scanf("%d%d", &l, &r); ans = 0;
	for (int i = 0; i < M; ++i) ans = max(ans, bit[i][r] - bit[i][l - 1]);
	printf("%d\n", r - l + 1 - ans);
}


int main()
{
	pre();
	int T; scanf("%d", &T);
	for (;T--;) Main(); 
}