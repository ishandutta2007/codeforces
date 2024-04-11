#include <cstdio>
#include <vector>

int n, q;
int a[200002];

int foam[500005];
std :: vector <int> factor[200002];

bool beer[200002];

typedef long long LL;

LL update (int x, int val) {

	LL ret = 0;
	for (int i = 1; i < 1 << factor[x].size(); i++) {
		int tmp = 1;
		for (int j = 0; j < factor[x].size(); j++) 
			if (i >> j & 1) tmp *= factor[x][j];
		
		if (__builtin_popcount(i) & 1) ret += foam[tmp];
		else ret -= foam[tmp];
		
		foam[tmp] += val;
	}
		
	return ret;
	
}

int main () {

	scanf ("%d %d", &n, &q);

	int tot = 0;
	LL ans = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", a + i);
		int tmp = a[i];
		for (int j = 2; j * j <= tmp; j++) {
			if (tmp % j == 0) {
				factor[i].push_back(j);
				while (tmp % j == 0) tmp /= j;				
			}
		}
		
		if (tmp > 1) factor[i].push_back(tmp);		
	}
	
	int x;
	while (q--) {
		scanf ("%d", &x);
		x--;
		
		if (beer[x]) {
			if (a[x] == 1) ans -= --tot;
			else ans -= (tot--) - update (x, -1);
		} else ans += (tot++) - update (x, 1);
		
		beer[x] ^= 1;
		
		printf ("%I64d\n", ans);
	}
	return 0;
}