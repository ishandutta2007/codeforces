#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

string s;
int n, p;
bool flag = 0;

bool KT(char x, int vt) {
    return (x != s[vt - 1] && x != s[vt - 2]);
}

bool Check(int dau) {
    bool found = 0;
    char i;
    for(i = s[dau] + 1; i < p + 'a'; i++)
    if(KT(i, dau)) {
        found = 1;
        break;
    }
    if(!found) return 0;
    if(flag) cout << i;
    char tr = s[dau - 1];
    for(int j = dau + 1; j < n + 2; j++) {
        found = 0;
        for(char k = 'a'; k < 'a' + p; k++)
        if(k != tr && k != i) {
            if(flag) cout << k;
            tr = i;
            i = k;
            found = 1;
            break;
        }
        if(!found) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> p;
    cin >> s;
    s = "QQ" + s;
    for(int i = n + 1; i >= 2; i--) {
        if(Check(i)) {
            flag = 1;
            char xx;
            for(int j = 2; j < i; j++)
                cout << s[j];
            Check(i);
            exit(0);
        }
    }
    cout << "NO\n";
    return 0;
}