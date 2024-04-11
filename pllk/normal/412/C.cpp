#include <iostream>

using namespace std;

int n, m;
char c[101010];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m = s.size();
        for (int j = 0; j < m; j++) {
            if (s[j] == '?') continue;
            if (c[j] == 0) c[j] = s[j];
            else if (c[j] != s[j]) c[j] = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        if (c[i] == 0) cout << "a";
        else if (c[i] == -1) cout << "?";
        else cout << c[i];
    }
    cout << endl;
}