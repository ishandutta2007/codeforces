#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;


LL A[3];
int main() {
    scanf("%lld%lld%lld", A, A+1, A+2);
    sort(A, A+3);

    if (A[2] > 2 * (A[0] + A[1])) {
        printf("%lld\n", A[0] + A[1]);
    } else {
        printf("%lld\n", (A[0] + A[1] + A[2]) / 3);
    }

    return 0;
}