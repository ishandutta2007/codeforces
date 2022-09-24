#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;


int main() {
    int N, M;
    scanf("%d%d", &M, &N);
    double B = M;
    double ans = 0;
    double off = 0, cur = 0;
    for (int i=1; i<=M; i++) {
        cur = pow(i / B, (double)N);
        ans += i * (cur - off);
        off = cur;
    }

    printf("%.12f\n", ans);

    return 0;
}