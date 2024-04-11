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

int _, x;
int main() {
    scanf("%d", &_);
    while (_--) {
        int ans = 0;
        scanf("%d", &x);
        while (x > 0) {
            ans = max(ans, x % 10);
            x /= 10;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
121
5
1000000000
*/