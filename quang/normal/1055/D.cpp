#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

int n;
char a[N][N], b[N][N];
int len[N];
int l[N], r[N];
int t[N];
char resS[N], resT[N];
int sz;

bool checkEqual(int id, int u) {
    if ((r[id] - l[id]) != (r[u] - l[u])) return 0;
    for (int i = l[id], j = l[u]; i <= r[id]; i++, j++) {   
        if (a[id][i] != a[u][j] || b[id][i] != b[u][j]) return 0;
    }
    return 1;
}

bool checkTrue(int u) {
    int cur = 0;
    for (int i = 1; i <= len[u]; i++) {
        while (cur && resS[cur + 1] != a[u][i]) {
            cur = t[cur];
        }
        cur += (resS[cur + 1] == a[u][i]);
        if (cur == sz) {
            if (l[u] == -1) return 0;
            return i - sz + 1 == l[u];
        }
    }
    return l[u] == -1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", b[i] + 1);
    }
    int id = -1;
    for (int i = 1; i <= n; i++) {
        len[i] = strlen(a[i] + 1);
        l[i] = r[i] = -1;
        for (int j = 1; j <= len[i]; j++) {
            if (a[i][j] != b[i][j]) {
                if (l[i] == -1) l[i] = j;
                r[i] = j;
            }
        }
        if (l[i] != -1 && id == -1) id = i;
    }
    assert(id != -1);
    
    int maxL = 1, maxR = len[id];
    for (int i = id + 1; i <= n; i++) {
        if (l[i] == -1) continue;
        if (!checkEqual(id, i)) {
            puts("NO");
            return 0;
        }

        int nowId = r[id];
        int nowI = r[i];
        while (nowId <= maxR && nowI <= len[i]) {
            if (a[id][nowId] != a[i][nowI] || b[id][nowId] != b[i][nowI]) break;
            nowId++;
            nowI++;
        }
        maxR = nowId - 1;
        nowId = l[id];
        nowI = l[i];
        while (nowId >= maxL && nowI >= 1) {
            if (a[id][nowId] != a[i][nowI] || b[id][nowId] != b[i][nowI]) break;
            nowId--;
            nowI--;
        }
        maxL = nowId + 1;
    }

    for (int i = id + 1; i <= n; i++) {
        if (l[i] == -1) continue;
        r[i] += maxR - r[id];
        l[i] -= l[id] - maxL;
    }
    l[id] = maxL;
    r[id] = maxR;

    int cur = 0;
    for (int i = maxL; i <= maxR; i++) {
        cur++;
        resS[cur] = a[id][i];
        resT[cur] = b[id][i];
    }
    sz = maxR - maxL + 1;

    cur = 0;
    t[1] = 0;
    for (int i = 2; i <= sz; i++) {
        while (cur && resS[cur + 1] != resS[i]) {
            cur = t[cur];
        }
        cur += (resS[cur + 1] == resS[i]);
        t[i] = cur;
    }

    for (int i = 1; i <= n; i++) {
        if (!checkTrue(i)) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    printf("%s\n", resS + 1);
    printf("%s\n", resT + 1);
    return 0;
}