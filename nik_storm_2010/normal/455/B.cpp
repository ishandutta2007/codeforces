#include <cstdio>
#include <map>
#include <cstring>

using namespace std;
const int N = 2e5;

struct trie {
    map <char, int> go;
    bool win, lose;
};

trie a[N];
char s[N];

void dfs(int x) {
    a[x].lose = (a[x].go.begin() == a[x].go.end() ? true : false);
    a[x].win = false;
    for (map <char, int>::iterator it = a[x].go.begin(); it != a[x].go.end(); it++) {
        int to = it -> second;
        dfs(to);
        if (a[to].win == false) a[x].win = true;
        if (a[to].lose == false) a[x].lose = true;
    }
}

int main() {
    int n, k, cnt = 0;
    scanf("%d %d\n", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s\n", s);
        int cur = 0;
        for (int j = 0; j < strlen(s); j++) {
            if (a[cur].go[s[j]] == 0) {
                cnt++;
                a[cur].go[s[j]] = cnt;
            }
            cur = a[cur].go[s[j]];
        }
    }
    dfs(0);
    if ((a[0].lose && a[0].win) || (!a[0].lose && a[0].win && k % 2 == 1)) puts("First"); else puts("Second");
    return 0;
}