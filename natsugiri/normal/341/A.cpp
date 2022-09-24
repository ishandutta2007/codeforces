#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b?gcd(b, a%b) : a; }

int N, A[100010];
LL sums[100010];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", A+i);
    sort(A, A+N);

    for (int i=0; i<N; i++) sums[i+1] = sums[i]+A[i];
    
    LL ans=0;
    for (int i=0; i<N; i++) {
	ans += LL(i)*A[i] - sums[i];
	ans += (sums[N] - sums[i+1]) - LL(N-1-i)*A[i]; 
	ans += A[i];
    }

    
    LL g = gcd(ans, N);

    cout << ans/g << ' ' << N/g << endl;
    return 0;
}