#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 110

using namespace std;

int n, m;
vector <int> a[N * 2], b;
long long res = 0;
bool kt[N * 2];

void DFS(int u) {
    kt[u] = 1;
    for(int i = 0; i < (int)a[u].size(); i++)
    if(!kt[a[u][i]]) DFS(a[u][i]);
}

int main() {
    //fi, fo;
    scanf("%d%d", &n, &m);
    int l;
    for(int i = 1; i <= n; i++) {
        int sl, lang;
        scanf("%d", &sl);
        if(!sl) b.push_back(i);
        else
        for(int j = 1; j <= sl ;j++) {
            scanf("%d", &lang);
            l = lang;
            a[i].push_back(lang + n);
            a[lang + n].push_back(i);
        }
    }
    for(int i = 0; i < (int)b.size(); i++) {
        res++;
        int u = b[i];
        a[u].push_back(l + n);
        a[l + n].push_back(u);
    }
    int d = 0;
    for(int i = 1; i <= n; i++)
    if(!kt[i]) {
        d++;
        DFS(i);
    }
    cout  << res + d - 1;
    return 0;
}