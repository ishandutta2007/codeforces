#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1005;
int N, P;
char s[maxn];

bool check (int v) {
    if (v >= 1 && s[v] == s[v-1])
        return false;
    if (v >= 2 && s[v] == s[v-2])
        return false;
    return true;
}

bool solve (int v) {

    while(true) {
        if (v >= N)
            return true;

        if (v < 0)
            return false;

        if (s[v] - 'a' == P - 1) {
            s[v] = 'a' - 1;
            v--;
        } else {

            int k = (s[v] - 'a' + 1) % P;
            s[v] = 'a' + k;

            if (check(v))
                v++;
        }
    }
    return false;
}

int main () {
    scanf("%d%d%s", &N, &P, s);
    if (!solve(N-1))
        printf("NO\n");
    else
        printf("%s\n", s);
    return 0;
}