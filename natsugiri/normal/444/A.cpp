#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M;
int X[555];
int main() {
    scanf("%d%d", &N, &M);
    for (int i=0; i<N; i++) scanf("%d", X+i);

    double ans = 0;
    for (;M--;) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        ans = max(ans, (double)(X[a]+X[b]) / c);
    }

    printf("%.20f\n", ans);

    return 0;
}