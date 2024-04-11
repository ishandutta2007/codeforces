#include <bits/stdc++.h>

using namespace std;
const int c=100005;
int n, k, cnt, kov[c][26];
bool nyer[c], veszit[c];
void dfs(int a) {
    bool lvl=1;
    for (int i=0; i<26; i++) {
        int x=kov[a][i];
        if (x) {
            lvl=0;
            dfs(x);
            if (!nyer[x]) {
                nyer[a]=1;
            }
            if (!veszit[x]) {
                veszit[a]=1;
            }
        }
    }
    if (lvl) {
        veszit[a]=1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cnt=1;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        int pos=1;
        for (auto x:s) {
            int y=x-'a';
            if (!kov[pos][y]) {
                kov[pos][y]=++cnt;
            }
            pos=kov[pos][y];
        }
    }
    dfs(1);
    if (nyer[1] && (veszit[1] || k%2)) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
    return 0;
}