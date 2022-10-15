#include <iostream>

#define ll long long int

using namespace std;

ll a, b;
string s;

ll pos[2][100][2];

int main() {
    cin >> a >> b;
    cin >> s;
    int p = s.length();
    int y = 0, x = 0;
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < p; i++) {
            if (y == b && x == a) {
                cout << "Yes\n";
                return 0;
            }
            pos[k][i][0] = y;
            pos[k][i][1] = x;
            if (s[i] == 'U') y++;
            if (s[i] == 'D') y--;
            if (s[i] == 'L') x--;
            if (s[i] == 'R') x++;
        }
    }
    for (int i = 0; i < p; i++) {
        ll y1 = pos[0][i][0];
        ll y2 = pos[1][i][0];
        ll yk = y2-y1;
        ll x1 = pos[0][i][1];
        ll x2 = pos[1][i][1];
        ll xk = x2-x1;
        bool w1 = false, w2 = false, w3 = false;
        if ((yk == 0 && y2 == b) ||
            (yk != 0 && (b-y1)%yk == 0 && (b-y1)/yk >= 0)) w1 = true;
        if ((xk == 0 && x2 == a) ||
            (xk != 0 && (a-x1)%xk == 0 && (a-x1)/xk >= 0)) w2 = true;
        if (yk == 0 || xk == 0 || (b-y1)/yk == (a-x1)/xk) w3 = true;
        if (w1 && w2 && w3) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}