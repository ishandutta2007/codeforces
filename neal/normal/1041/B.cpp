#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    long long A, B, X, Y;
    scanf("%lld %lld %lld %lld", &A, &B, &X, &Y);
    long long G = __gcd(X, Y);
    X /= G;
    Y /= G;
    printf("%lld\n", min(A / X, B / Y));
}