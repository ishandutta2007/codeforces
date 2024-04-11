#include <iostream>

using namespace std;

int c;
int p[111];
int r;
int v[111];

int main() {
    string x;
    cin >> x;
    p[1] = 1;
    int c = 1;
    while (true) {
        string a;
        cin >> a;
        if (a == "+") {
            cin >> a;
            c++;
            p[c] = 1;
        } else if (a == "-") {
            cin >> a;
            c++;
            p[c] = -1;
        } else {
            cin >> r;
            break;
        }
    }
    int u = 0;
    for (int i = 1; i <= c; i++) {
        u += p[i];
        v[i] = 1;
    }
    if (u < r) {
        for (int i = 1; i <= c; i++) {
            if (p[i] != 1) continue;
            int x = min(r-1,r-u);
            v[i] += x;
            u += x;
        }
    } else if (u > r) {
        for (int i = 1; i <= c; i++) {
            if (p[i] != -1) continue;
            int x = min(r-1,u-r);
            v[i] += x;
            u -= x;
        }
    }
    if (u == r) {
        cout << "Possible\n";
        cout << v[1] << " ";
        for (int i = 2; i <= c; i++) {
            if (p[i] == 1) cout << "+ ";
            else cout << "- ";
            cout << v[i] << " ";
        }
        cout << "= " << r << "\n";
    } else {
        cout << "Impossible\n";
    }
}