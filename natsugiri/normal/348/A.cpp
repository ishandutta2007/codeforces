#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, A[100010];
LL sum, k;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    for (int i=0; i<N; i++) {
	sum += A[i];
	k = max(k, LL(A[i]));
    }

    LL l=k-1, r=10000000000000LL, m;
    for (;r-l>1;) {
	m = (l+r)/2;
	if (m*(N-1) >= sum) r = m;
	else l = m;
    }

    cout << r << endl;

    return 0;
}