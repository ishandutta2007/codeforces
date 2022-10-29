#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        for (int i = 0; i < 9; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 9; j++) {
                if (s[j] == '2') s[j] = '1';
            }
            cout << s << '\n';
        }
    }
    return 0;
}