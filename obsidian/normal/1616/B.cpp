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
int _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%s", &n, s);
        if (n == 1) {
            printf("%s%s\n", s, s);
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (i == 0 && s[i] <= s[i + 1]) {
                printf("%c%c\n", s[0], s[0]);
                break;
            }
            if (i == n - 1) {
                printf("%s", s);
                for (int j = n - 1; j >= 0; --j) printf("%c", s[j]);
                puts("");
                break;
            }
            if (s[i] < s[i + 1]) {
                for (int j = 0; j <= i; ++j) printf("%c", s[j]);
                for (int j = i; j >= 0; --j) printf("%c", s[j]);
                puts("");
                break;
            }
        }
    }
    return 0;
}

/*
4
10
codeforces
9
cbacbacba
3
aaa
4
bbaa
*/