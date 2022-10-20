#include <bits/stdc++.h>
#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

int n;
string s[N];

void Them(int x) {
    for(int i = 0; i < s[x].size(); i++)
    if(s[x][i] == '?') {
        if(i == 0)
            s[x][i] = '1';
        else
            s[x][i] = '0';
    }
}

int Tim(int u, int v) {
    for(int i = 0; i < s[u].size(); i++)
        if(s[u][i] != '?' && s[v][i] != '?' && s[u][i] != s[v][i])
            return i;
    return s[u].size();
}

void Push(int u, int vt) {
    for(int i = vt - 1; i >= -1; i--){
        if(i == -1) {
            cout << "NO\n";
            exit(0);
        }
        if(s[u][i] == '?' && s[u - 1][i] != '9') {
            s[u][i] = s[u - 1][i] + 1;
            break;
        }
        if(s[u][i] == '?') s[u][i] = '0';
    }
    for(int i = 0; i < s[u].size(); i++)
        if(s[u][i] == '?') s[u][i] = s[u - 1][i];
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
    Them(1);
    for(int i = 2; i <= n; i++) {
        if(s[i].size() < s[i - 1].size()) {
            cout << "NO\n";
            return 0;
        }
        if(s[i].size() > s[i - 1].size()) {
            Them(i);
            continue;
        }
        int val = Tim(i, i - 1);
        for(int j = val + 1; j < s[i].size(); j++)
            if(s[i][j] == '?')
                s[i][j] = '0';
        if(val >= s[i].size()) {
            Push(i, val);
            continue;
        }
        if(s[i][val] > s[i - 1][val]) {
            for(int j = 0; j < val; j++)
            if(s[i][j] == '?')
                s[i][j] = s[i - 1][j];
            continue;
        }
        Push(i, val);
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << s[i] << endl;
    return 0;
}