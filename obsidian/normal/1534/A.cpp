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
const int V = 60;
char s[V][V];

int _, n, m;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        int sw = 0;
        int sr = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int k = (i + j) % 2;
                if (s[i][j] == 'W') sw |= (1 << k);
                else if (s[i][j] == 'R') sr |= (1 << k);
            }
        }
        if (sw == 3 || sr == 3 || (sw & sr) != 0) {
            puts("NO");
            continue;
        }
        if (sw == 0) {
            if (sr == 0) sw = 1, sr = 2;
            else sw = 3 ^ sr;
        } else sr = 3 ^ sw;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int k = (i + j) % 2;
                if (sw == (1 << k)) s[i][j] = 'W';
                else s[i][j] = 'R';
            }
        }
        puts("YES");
        for (int i = 0; i < n; ++i, puts(""))
            for (int j = 0; j < m; ++j) printf("%c", s[i][j]);
    }
    return 0;
}

/*
3
4 6
.R....
......
......
.W....
4 4
.R.W
....
....
....
5 1
R
W
R
W
R
*/