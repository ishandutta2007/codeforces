#include <iostream>
#include <vector>

using namespace std;

int m, s;

bool ok(int a, int b, bool x) {
    int s1 = 0;
    if (x) s1 = 1;
    int s2 = a*9;
    return s1 <= b && b <= s2;
}

int main() {
    cin >> m >> s;
    if (m == 1 && s == 0) {
        cout << "0 0\n";
        return 0;
    }
    if (!ok(m, s, true)) {
        cout << "-1 -1\n";
        return 0;
    }
    vector<int> s1;
    int u = s;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i == 0 && j == 0) continue;
            if (u-j < 0) continue;
            if (!ok(m-i-1, u-j, false)) continue;
            s1.push_back(j);
            u -= j;
            break;
        }
    }
    vector<int> s2;
    u = s;
    for (int i = 0; i < m; i++) {
        for (int j = 9; j >= 0; j--) {
            if (i == 0 && j == 0) continue;
            if (u-j < 0) continue;
            if (!ok(m-i-1, u-j, false)) continue;
            s2.push_back(j);
            u -= j;
            break;
        }
    }
    for (int i = 0; i < s1.size(); i++) cout << s1[i];
    cout << " ";
    for (int i = 0; i < s2.size(); i++) cout << s2[i];
    cout << "\n";
}