#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define RFOR(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100000 + 100;
int t, n, m, up, lo, di;
char s[110];

int main()
{
    //freopen("test.in" ,"r", stdin);
    scanf("%d", &t);
    while (t--) {
        up = lo = di = 0;
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = 1; i <= n; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') ++up;
            if (s[i] >= 'a' && s[i] <= 'z') ++lo;
            if (s[i] >= '0' && s[i] <= '9') ++di;
        }
        if (up && lo && di) {
            printf("%s\n", s + 1);
        }
        if (!up && lo && di) {
            for (int i = 1; i <= n; ++i) {
                if (s[i] >= 'a' && s[i] <= 'z' && lo > 1) { s[i] = toupper(s[i]); break; }
                if (s[i] >= '0' && s[i] <= '9' && di > 1) { s[i] = 'A'; break; }
            }
            printf("%s\n", s + 1);
        }
        if (!lo && up && di) {
            for (int i = 1; i <= n; ++i) {
                if (s[i] >= 'A' && s[i] <= 'Z' && up > 1) { s[i] = tolower(s[i]); break; }
                if (s[i] >= '0' && s[i] <= '9' && di > 1) { s[i] = 'a'; break; }
            }
            printf("%s\n", s + 1);
        }
        if (!di && up && lo) {
            for (int i = 1; i <= n; ++i) {
                if ((s[i] >= 'A' && s[i] <= 'Z' && up > 1) || (s[i] >= 'a' && s[i] <= 'z' && lo > 1)) { s[i] = '1'; break; }
            }
            printf("%s\n", s + 1);
        }
        if (!up && !lo && di) {
            for (int i = 1; i < n; ++i) if (s[i] >= '0' && s[i] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9') {
                s[i] = 'A', s[i + 1] = 'a';
                break;
            }
            printf("%s\n", s + 1);
        }
        if (!up && lo && !di) {
            for (int i = 1; i < n; ++i) if (s[i] >= 'a' && s[i] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z') {
                s[i] = 'A', s[i + 1] = '1';
                break;
            }
            printf("%s\n", s + 1);
        }
        if (up && !lo && !di) {
            for (int i = 1; i < n; ++i) if (s[i] >= 'A' && s[i] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z') {
                s[i] = 'a', s[i + 1] = '1';
                break;
            }
            printf("%s\n", s + 1);
        }
    }
    return 0;
}