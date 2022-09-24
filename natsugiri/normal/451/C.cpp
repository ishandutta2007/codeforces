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


int T;
LL N, K, D0, D1;

// W1 - W0, W2 - W1, 
bool calc(LL X, LL Y) {
    if (X > K) return false;
    if ((K - X) % 3) return false;

    if (Y > N-K) return false;
    if ((N-K-Y) % 3) return false;

    return true;
}

int main() {
    //scanf("%d", &T);
    cin >> T;
    REP ($, T) {
	//scanf("%lld %lld %lld %lld", &N, &K, &D0, &D1);
	cin >> N >> K >> D0 >> D1;

	bool yes = false;

	// 0, d0, d0 + d1
	// D0, D1
	yes |= calc(2 * D0 + D1, D0 + 2 * D1);

	// 0, d0, d0-d1
	// D0, -D1
	if (D0 >= D1) yes |= calc(2 * D0 - D1, D0 + D1);

	// d0, 0, d1
	// -D0, D1
	LL ma = max(D0, D1);
	yes |= calc(D0 + D1, 3 * ma - D0 - D1);

	// d0 + d1, d1, 0
	// -D0, -D1
	yes |= calc(D0 + 2 * D1, 2 * D0 + D1);

	// d1 - d0, d1, 0
	// D0, -D1
	if (D1 >= D0) yes |= calc(2 * D1 - D0, D0 + D1);

	puts(yes ? "yes" : "no");
    }

    return 0;
}