#include <iostream>
#include <algorithm>

using namespace std;

int n;

bool valid1(int y, int x) {
    cout << "? " << y << " " << x << " " << n << " " << n << endl;
    string s;
    cin >> s;
    return s == "YES";
}

bool valid2(int y, int x) {
    cout << "? " << 1 << " " << 1 << " " << y << " " << x << endl;
    string s;
    cin >> s;
    return s == "YES";
}

int main() {
    cin >> n;
    int y = 1, x = 1;
    string r1 = "";
    for (int i = 0; i < n-1; i++) {
        if (x+1 <= n && valid1(y,x+1)) {
            x++;
            r1 += "R";
        } else {
            y++;
            r1 += "D";
        }
    }
    string r2 = "";
    y = n; x = n;
    for (int i = 0; i < n-1; i++) {
        if (y-1 >= 1 && valid2(y-1,x)) {
            y--;
            r2 += "D";
        } else {
            x--;
            r2 += "R";
        }
    }
    reverse(r2.begin(),r2.end());
    cout << "! " << r1 << r2 << endl;
}