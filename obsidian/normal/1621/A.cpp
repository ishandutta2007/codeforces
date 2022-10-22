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
int _, n, k;
char s[120][120];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &k);
        if (2 * k - 1 > n) {puts("-1"); continue;}
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) s[i][j] = '.';
        for (int i = 0; i < k; ++i) {
            s[i * 2][i * 2] = 'R';
        }
        for (int i = 0; i < n; ++i, puts(""))for(int j = 0; j < n; ++j) printf("%c", s[i][j]);
    }
    return 0;
}

/*
5
3 2
3 3
1 1
5 2
40 33
*/