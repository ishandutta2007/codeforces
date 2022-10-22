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
LL pt[20], x;;
int _;
int main() {
    pt[0] = 2050;
    for (int i = 1; i <= 15; ++i) pt[i] = pt[i - 1] * 10;
    //printf("%lld %lld\n", pt[14], pt[15]);
    scanf("%d", &_);
    while (_--) {
        scanf("%lld", &x);
        int ans = 0;
        for (int i = 15; i >= 0; --i) {
            ans += x / pt[i];
            x %= pt[i];
        }
        if (x != 0) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

/*
6
205
2050
4100
20500
22550
25308639900
*/