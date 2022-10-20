#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int n, m;
vector <int> a[900];
string s1, s2;
int used[900], cnt = 0;

void DFS(int u) {
    used[u] = cnt;
    for(int i = 0; i < (int)a[u].size(); i++) {
        int v = a[u][i];
        if(used[v] != cnt) DFS(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m;
    cin >> s1 >> s2;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
        int vt;
        if(s1[i] == '<') vt = j - 1;
        else vt = j + 1;
        if(vt >= 0 && vt < m) a[i * m + j].push_back(i * m + vt);
        if(s2[j] == 'v') vt = i + 1;
        else vt = i - 1;
        if(vt >= 0 && vt < n) a[i * m + j].push_back(vt * m + j);
    }
    for(int i = 0; i < n * m; i++) {
        cnt++;
        DFS(i);
        for(int j = 0; j < n * m; j++)
            if(used[j] != cnt) {
                cout << "NO";
                return 0;
            }
    }
    cout <<"YES";
    return 0;
}