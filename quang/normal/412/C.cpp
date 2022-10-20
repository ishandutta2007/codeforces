#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int n;
string s[100010];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 0; i < (int)s[1].size(); i++) {
        char res = '?';
        bool flag = 0;
        for(int j = 1; j <= n; j++) {
            if(res != '?' && s[j][i] != '?' && res != s[j][i]) {
                res = '?';
                flag = 1;
                break;
            }
            if(res == '?') res = s[j][i];
        }
        if(!flag && res == '?') res = 'a';
        cout << res;
    }
    return 0;
}