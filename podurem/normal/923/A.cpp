#include <bits/stdc++.h>
 
using namespace std;

#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;

const int dd = (int)1e6 + 7;

vector<int> F;
int C[dd];

int main() {
	int X;
	scanf("%d", &X);

	for (int i = 2; i <= X; ++i) if (C[i] == 0) {
		F.push_back(i);
		for (ll j = 1ll * i * i; j <= X; j += i)
			C[j] = 1;
	}

	int L = X;
	for (int i : F) if (X % i == 0)
		L = min(L, max(i + 1, X - i + 1));
	
	int ans = X;
	for (int i : F) {
		int J = ((L - 1) / i + 1) * i;
		if (J <= X) ans = min(ans, max(i + 1, J - i + 1));
	}
	printf("%d\n", ans);
    return 0;
}