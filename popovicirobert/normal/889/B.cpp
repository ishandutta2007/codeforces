#include <bits/stdc++.h>
#define lsb(x)

using namespace std;

const int MAXN = (int) 1e5;

string str[MAXN + 1];

inline void fail() {
    cout << "NO";
    exit(0);
}

int fr[26], nxt[26];
bool first[26], in[26];
bool vis[26];

string sol[MAXN + 1];

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    memset(nxt, -1, sizeof(nxt));
    for(i = 1; i <= n; i++) {
        cin >> str[i];
        memset(fr, 0, sizeof(fr));
        for(j = 0; j < str[i].size(); j++) {
            str[i][j] -= 'a';
          //  ok[str[i][j]] = 1;
        }
        first[str[i][0]] = 1;
        for(j = 0; j + 1 < str[i].size(); j++) {
            in[str[i][j + 1]] = 1;
            if(nxt[str[i][j]] != -1 && nxt[str[i][j]] != str[i][j + 1])
                fail();
            nxt[str[i][j]] = str[i][j + 1];
            fr[str[i][j]]++;
            if(fr[str[i][j]] == 2)
                fail();
        }
    }
    int cnt = 0;
    for(i = 0; i < 26; i++) {
        if(first[i] == 1 && vis[i] == 0 && in[i] == 0) {
            j = i;
            cnt++;
            while(j > -1 && vis[j] == 0) {
                vis[j] = 1;
                sol[cnt].push_back(j + 'a');
                j = nxt[j];
            }
            if(j > -1)
                fail();
        }
    }
    for(i = 0; i < 26; i++) {
        if(first[i] == 1 && vis[i] == 0)
            fail();
    }
    sort(sol + 1, sol + cnt + 1);
    for(i = 1; i <= cnt; i++) {
        cout << sol[i];
    }
    //cin.close();
    //cout.close();
    return 0;
}