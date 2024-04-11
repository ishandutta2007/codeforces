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
int _, K;
int w[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%s%d", s, &K);
        int n = strlen(s);
        for (int i = 0; i < n; ++i) w[i] = 1;
        for (int i = 0; i < n; ++i)
            if (s[i] == '0') {
                if (i >= K) w[i - K] = 0;
                if (i + K < n) w[i + K] = 0;
            }
        bool ok = true;
        for (int i = 0; i < n; ++i)
            if (s[i] == '1') {
                bool has = false;
                if (i >= K && w[i - K] == 1) has = true;
                if (i + K < n && w[i + K] == 1) has = true;
                if (!has) ok = false;
            }
        if (!ok) puts("-1");
        else {
            for (int i = 0; i < n; ++i) printf("%d", w[i]); puts("");
        }
    }
    return 0;
}

/*
3
101110
2
01
1
110
1
*/