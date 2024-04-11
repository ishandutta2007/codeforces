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
int _, a, b;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &a, &b);
        if (a % 2 != b % 2) puts("-1");
        else if (a == 0 && b == 0) puts("0");
        else if (a == b) puts("1");
        else if (a + b == 0) puts("1");
        else puts("2");
    }
    return 0;
}

/*
6
1 2
3 5
5 3
6 6
8 0
0 0
*/