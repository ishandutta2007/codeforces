#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100010

using namespace std;

string s;
int m;
int sl[3][N];

void CB() {
    s = "Q" + s;
    for(int i = 1; i < (int)s.size(); i++) {
        sl[0][i] = sl[0][i - 1];
        sl[1][i] = sl[1][i - 1];
        sl[2][i] = sl[2][i - 1];
        if(s[i] == 'x') sl[0][i]++;
        if(s[i] == 'y') sl[1][i]++;
        if(s[i] == 'z') sl[2][i]++;
    }
}

int main() {
   // fi, fo;
    cin >> s;
    cin >> m;
    CB();
    while(m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int slx = sl[0][r] - sl[0][l - 1];
        int sly = sl[1][r] - sl[1][l - 1];
        int slz = sl[2][r] - sl[2][l - 1];
        if(r - l + 1 < 3) {
            cout << "YES\n";
            continue;
        }
        if(abs(slx - slz) <= 1 && abs(slz - sly) <= 1 && abs(slx - sly) <= 1) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}