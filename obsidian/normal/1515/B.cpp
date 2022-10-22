#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;

bool ok(int n) {
    for (int i = 1; i * i <= n; ++i) if (i * i == n) return true;
    return false;
}

int _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        if ((n % 4 == 0 && ok(n / 4)) || (n % 2 == 0 && ok(n / 2))) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
3
2
4
6
*/