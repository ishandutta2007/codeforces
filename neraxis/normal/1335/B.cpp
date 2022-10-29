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
        int a, b, n;
        cin >> n >> a >> b;
        string s = "";
        while (1) {
            for (int i = 0; i < b; i++) {
                s.pb('a' + i);
                if (s.size() == n) break;
            }
            if (s.size() == n) break;
        }
        cout << s << '\n';
    }
    return 0;
}