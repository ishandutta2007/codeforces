#include <iostream>

using namespace std;

int n;
string s[333];
int a[128], b[128];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == n-1-j) a[s[i][j]]++;
            else b[s[i][j]]++;
        }
    }
    bool v = false;
    int c1 = 0, c2 = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (a[i] && b[i]) v = true;
        if (a[i]) c1 = i;
        if (b[i]) c2 = i;
    }
    if (!v && a[c1]+b[c2] == n*n && a[c1] == 2*n-1) cout << "YES\n";
    else cout << "NO\n";
}