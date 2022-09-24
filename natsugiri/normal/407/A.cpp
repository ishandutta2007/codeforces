#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int gcd(int a, int b) {
    while (b) {
	a %= b;
	swap(a, b);
    }
    return a;
}

int main() {
    int A, B;
    scanf("%d%d", &A, &B);
    int g = gcd(A, B);
    A /= g;
    B /= g;
    
    for (int i=1; i<=g; i++) {
	for (int j=1; j<=g; j++) {
	    if (i*i + j*j == g*g && A*i != B*j) {
		puts("YES");
		puts("0 0");
		printf("%d %d\n", A*i, A*j);
		printf("%d %d\n", B*j, -B*i);
		return 0;
	    }
	}
    }

    puts("NO");
    return 0;
}