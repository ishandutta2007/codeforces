#include <iostream>

using namespace std;

string s;
int c;
int t[101010];

int main() {
    cin >> s;
    int z = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') z++;
        if (s[i] == ')') z--;
        if (s[i] == '#') c++;
    }
    if (z <= 0) {
        cout << "-1\n";
        return 0;
    }
    int q = 0;
    int u = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') q++;
        if (s[i] == ')') q--;
        if (s[i] == '#') {
            u++;
            if (u < c) {
                t[u-1] = 1;
                q--;
                z--;
            } else {
                if (z <= 0) {
                    cout << "-1\n";
                    return 0;
                }
                t[u-1] = z;
                q -= z;
                z = 0;
            }
        }
        if (q < 0) {
            cout << "-1\n";
            return 0;
        }
    }
    if (q != 0) {
        cout << "-1\n";
    }
    for (int i = 0; i < c; i++) cout << t[i] << "\n";
}