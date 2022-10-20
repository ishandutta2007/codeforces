#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100010

using namespace std;

int n, cnt[N][26];
vector <int> neighbor[N];
bool past[N];
char res[N];

void Get(int u) {
    past[u] = 1;
    for(int i = 0; i < (int)neighbor[u].size(); i++) {
        int v = neighbor[u][i];
        if(!past[v]) {
            Get(v);
            for(int j = 0; j < 26; j++)
                cnt[u][j] += cnt[v][j];
        }
    }
    int pos = 0;
    while(pos < 25 && cnt[u][pos + 1] < 2)
        pos++;
    while(cnt[u][pos]) pos--;
    cnt[u][pos]++;
    res[u] = 'A' + pos;
    for(int i = pos + 1; i < 26; i++)
        cnt[u][i] = 0;
}

int main() {
    //fi, fo;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        neighbor[u].push_back(v);
        neighbor[v].push_back(u);
    }
    Get(1);
    for(int i = 1; i <= n; i++) printf("%c ", res[i]);
    return 0;
}