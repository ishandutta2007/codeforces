#include <iostream>

using namespace std;

int n, k;
string s;

int main() {
    cin >> n >> k;
    cin >> s;
    int a = 0;
    while (s[a] != '.') a++;
    a++;
    int u = -1;
    for (int i = a; i < n; i++) {
        if (s[i] >= '5') {
            u = i;
            break;
        }
    }
    if (u == -1) {
        cout << s << "\n";
        return 0;
    }
    s = s.substr(0,u+1);
    bool ok = true;
    for (int z = 0; z < k; z++) {
        if (s[u] < '5') break;
        s.pop_back();
        ok = false;
        for (int i = u-1; i >= 0; i--) {
            if (s[i] == '.') continue;
            if (s[i] == '9') s[i] = '0';
            else {s[i]++; ok = true; break;}
        }
        u--;
    }
    if (!ok) s = "1"+s;
    if (s.back() == '.') s = s.substr(0,s.size()-1);
    cout << s << "\n";
}