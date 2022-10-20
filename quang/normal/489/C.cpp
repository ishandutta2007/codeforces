#include <bits/stdc++.h>
#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

int m, s;

string Getmax() {
    if(9 * m < s) return "-1";
    int sl = s;
    string res = "";
    for(int i = 1; i <= m; i++) {
        if(sl > 9) {
            res += '9';
            sl -= 9;
        } else {
            res += (char)(sl + '0');
            sl = 0;
        }
    }
    return res;
}

string Getmin() {
    if(9 * m < s) return "-1";
    int sl = s - 1;
    string res;
    for(int i = 1; i < m; i++) {
        if(sl > 9) {
            res += '9';
            sl -= 9;
        } else {
            res += (char)(sl + '0');
            sl = 0;
        }
    }
    res += (char)(sl + '1');
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi,fo;
    cin >> m >> s;
    if(s == 0) {
        if(m == 1) cout << 0 << " " << 0;
        else cout << -1 << " " << -1;
        return 0;
    }
    cout << Getmin() << " " ;
    cout << Getmax();
    return 0;
}