#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) + rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

using namespace std;

int main() {
	int n, m = 0, i = 1;
	cin >> n;
	while(n >= i) n -= i, ++m, i <<= 1;
	if(n) ++m;
	cout << m << endl;
	return 0;
}