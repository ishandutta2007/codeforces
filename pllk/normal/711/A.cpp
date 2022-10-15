#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> x;
bool ok;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (!ok && s[0] == 'O' && s[1] == 'O') {
            s[0] = '+'; s[1] = '+';
            ok = true;
        }
        if (!ok && s[3] == 'O' && s[4] == 'O') {
            s[3] = '+'; s[4] = '+';
            ok = true;
        }
        x.push_back(s);
    }
    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << x[i] << "\n";
    } else {
        cout << "NO\n";
    }
}