#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int a, b, ac, bc;
string s;

void Timcuoi() {
    ac = bc = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == 'L') ac--;
        if(s[i] == 'R') ac++;
        if(s[i] == 'U') bc++;
        if(s[i] == 'D') bc--;
    }
}

bool kt(int x, int y) {
    if(ac && bc) {
        x = a - x;
        y = b - y;
        if(x % ac || y % bc) return 0;
        if(x / ac != y / bc) return 0;
        return (x / ac >= 0);
    }
    if(ac && !bc) {
        if(y != b) return 0;
        x = a - x;
        if(x % ac) return 0;
        return (x / ac >= 0);
    }
    if(!ac && bc) {
        if(a != x) return 0;
        y = b - y;
        if(y % bc) return 0;
        return (y / bc >= 0);
    }
    return (a == x && b == y);
}

void Timkq() {
    int x, y;
    x = y = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == 'L') x--;
        if(s[i] == 'R') x++;
        if(s[i] == 'U') y++;
        if(s[i] == 'D') y--;
        if(kt(x, y)) {
            cout << "Yes";
            return;
        }
    }
    if(kt(0, 0)) {
        cout << "Yes";
        return;
    }
    cout << "No";
}

int main() {
    //fi, fo;
    scanf("%d%d", &a, &b);
    cin >> s;
    Timcuoi();
    Timkq();
}