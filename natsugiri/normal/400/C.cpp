#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


int main() {
    int N, M, X, Y, Z, P;
    scanf("%d%d%d%d%d%d", &N, &M, &X, &Y, &Z, &P);

    for (int i=0; i<P; i++) {
	int a, b;
	scanf("%d%d", &a, &b);

	int n = N, m = M;
	for (int i=0; i<X%4; i++) {
	    int _a = b,
		_b = n-a+1;
	    a = _a;
	    b = _b;
	    swap(n, m);
	}
	if (Y%2) {
	    b = m-b+1;
	}
	for (int i=0; i<Z%4; i++) {
	    int _a = m-b+1,
		_b = a;
	    a = _a;
	    b = _b;
	    swap(n, m);
	}

	printf("%d %d\n", a, b);
    }

	
    return 0;
}