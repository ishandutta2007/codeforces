#include<bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f;

int sqr (int x) {
    return x * x;
}

int main() {
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    printf("%d\n", sqr(a + b + f) - sqr(b) - sqr(d) - sqr(f));
    return 0;
}