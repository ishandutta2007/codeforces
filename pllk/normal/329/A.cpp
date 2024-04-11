#include <iostream>

using namespace std;

int n;
string q;

int r[500];
int s[500];

int a, b;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q;
        for (int j = 1; j <= n; j++) {
            if (q[j-1] == '.') {r[i] = j; s[j] = i;}
        }
    }
    for (int i = 1; i <= n; i++) {
        if (r[i]) a++;
        if (s[i]) b++;
    }
    if (a < n && b < n) {
        cout << -1 << endl;
    } else if (a == n) {
        for (int i = 1; i <= n; i++) cout << i << " " << r[i] << endl;
    } else {
        for (int i = 1; i <= n; i++) cout << s[i] << " " << i << endl;
    }
}