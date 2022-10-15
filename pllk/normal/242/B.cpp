#include <iostream>

using namespace std;

int n;
int s[100000][2];
int a, b;
int t;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i][0] >> s[i][1];
        if (s[i][0] < a || a == 0) a = s[i][0];
    }
    for (int i = 0; i < n; i++) {
        if (s[i][0] == a && s[i][1] > b) {
            b = s[i][1];
            t = i;
        }
    }
    int v = 0;
    for (int i = 0; i < n; i++) {
        if (s[i][1] > b) v = 1;
    }
    if (v == 0) cout << t+1 << endl;
    else cout << -1 << endl;
}