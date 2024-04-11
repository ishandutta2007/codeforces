#include <iostream>

using namespace std;

int n, m;
string s;
int a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> s;
    s = "*"+s+"*";
    for (int i = 1; i <= n; i++) {
        if (s[i] == '.') a++;
        if (s[i] == '.' && s[i+1] != '.') b++;
    }
    for (int i = 0; i < m; i++) {
        int x;
        char c;
        cin >> x >> c;
        bool ok = false;
        if (s[x] == '.' && c == '.') ok = true;
        if (s[x] != '.' && c != '.') ok = true;
        if (!ok) {
            s[x] = c;
            if (c == '.') {
                a++;
                if (s[x-1] == '.') b--;
                if (s[x+1] != '.') b++;
            } else {
                a--;
                if (s[x+1] != '.') b--;
                if (s[x-1] == '.') b++;
            }
        }
        cout << a-b << "\n";
    }
}