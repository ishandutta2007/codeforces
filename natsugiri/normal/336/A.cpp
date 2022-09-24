#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int x, y;
int sx, sy;
int main() {
    scanf("%d%d", &x, &y);

    if (x<0) { sx=-1; x=-x; } else { sx=1; }
    if (y<0) { sy=-1; y=-y; } else { sy=1; }

    pair<int,int> A(0, sy*(x+y)), C(sx*(x+y), 0);
    if (A>C) swap(A, C);
    printf("%d %d %d %d\n", A.first, A.second, C.first, C.second);

    return 0;
}