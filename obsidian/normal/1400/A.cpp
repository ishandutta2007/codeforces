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

int _, n;
char s[120];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        scanf("%s", s);
        for (int i = 0; i < n; ++i) printf("%c", s[i * 2]); puts("");
    }
    return 0;
}

/*
4
1
1
3
00000
4
1110000
2
101
*/