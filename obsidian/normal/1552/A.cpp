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
const int V = 50;
char s[V];
int a[V], b[V], _, n;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%s", &n, s);
        for (int i = 0; i < n; ++i) a[i] = b[i] = s[i] - 'a';
        sort(b, b + n);
        int ans = n;
        for (int i = 0; i < n; ++i) if (a[i] == b[i]) --ans;
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
3
lol
10
codeforces
5
aaaaa
4
dcba
*/