//#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>
#include <unordered_map>

using namespace std;

const int maxn = (int)2e5 + 10;
int v[maxn];
int sz[maxn];
int sum_pref[maxn];
int sum_suff[maxn];
int max_pref[maxn];
int max_suff[maxn];

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        scanf("%d", &sz[i]);
    }

    sum_pref[0] = v[0];
    max_pref[0] = sz[0];

    for (int i = 1; i < n; i++) {
        sum_pref[i] = sum_pref[i - 1] + v[i];
        max_pref[i] = max(max_pref[i - 1], sz[i]);
    }

    sum_suff[n - 1] = v[n - 1];
    max_suff[n - 1] = sz[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        sum_suff[i] = sum_suff[i + 1] + v[i];
        max_suff[i] = max(max_suff[i + 1], sz[i]);
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d ", sum_suff[i + 1] * max_suff[i + 1]);
        } else if (i == n - 1) {
            printf("%d", sum_pref[i - 1] * max_pref[i - 1]);
        } else {
            printf("%d ", (sum_pref[i - 1] + sum_suff[i + 1]) * max(max_pref[i - 1], max_suff[i + 1]));
        }
    }

    return 0;
}