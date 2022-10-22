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
const int V = 100100;
char s[V];
int a[V], _;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s", s);
        int n = strlen(s);
        for (int i = 0; i < n; ++i) a[i] = (s[i] - 'a');
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            bool same = false;
            for (int j = 1; j <= 2 && i - j >= 0; ++j) {
                if (a[i] == a[i - j]) same = true;
            }
            if (same) {ans++, a[i] = -1;}
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
7
babba
abaac
codeforces
zeroorez
abcdcba
bbbbbbb
a
*/