#include <cstdio>
#include <cstring>

const int N = 2000002;

bool prime[N];

int main () {
	memset (prime, 1, sizeof prime);
	prime[0] = prime[1] = 0;
	for (int i=2; i<N; i++) if (prime[i]) for (int j=2*i; j<N; j+=i) prime[j] = 0;
	
	int n;
	scanf ("%d", &n);
	int a[n];
	for (int i=0; i<n; i++) scanf ("%d", a + i);
	
	int one = 0;
	int genap = 0;
	for (int i=0; i<n; i++) {
		if (a[i] == 1) one++;
		else if (prime[a[i] + 1]) genap = a[i];
	}
	
	if (one + (genap > 0) >= 2) {
		printf ("%d\n", one + (genap > 0));
		for (int i=0; i<one; i++) printf ("%d ", 1);
		if (genap) printf ("%d\n", genap);
		return 0;
	}
	
	for (int i=0; i<n; i++) {
		if (a[i] & 1) 
			for (int j=0; j<n; j++)
				if (a[j] % 2 == 0)
					if (prime[a[i] + a[j]]) {
						return 0 * printf ("%d\n%d %d\n", 2, a[i], a[j]);
					}
	}	
	
	printf ("1\n%d\n", a[0]);
	return 0;
}