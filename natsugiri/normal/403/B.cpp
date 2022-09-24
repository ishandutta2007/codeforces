#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
using namespace std;

typedef long long LL;

const int INF = 1<<29;


set<int>bad;
int F(int n) {
    int r = 0;
    for (int i=2; i*i<=n; i++) {
	if (n % i == 0) {
	    int d = 1;
	    if (bad.count(i)) d = -1;
	    while (n % i == 0) {
		r += d;
		n /= i;
	    }
	}
    }
    if (n>1) {
	if (bad.count(n)) r--;
	else r++;
    }
    return r;
}
int gcd(int a, int b) {
    while (b) {
	a %= b;
	swap(a, b);
    }
    return a;
}


int N, M, A[5100], B[5100];

int main() {
    scanf("%d%d", &N, &M);

    for (int i=0; i<N; i++) scanf("%d", A+i);
    for (int i=0; i<M; i++) scanf("%d", B+i);
    for (int i=0; i<M; i++) bad.insert(B[i]);

    for (int l=N; l>0; l--) {
	int g = A[0];
	for (int i=1; i<l; i++) g = gcd(A[i], g);
	if (F(g) < 0) for (int i=0; i<l; i++) A[i] /= g;
    }

    int ans = 0;
    for (int i=0; i<N; i++) ans += F(A[i]);
    
    printf("%d\n", ans);

    return 0;
}