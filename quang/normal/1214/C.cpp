#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
char s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> (s + 1);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') tot++;
        else tot--;
    }
    if (tot != 0) {
        cout << "No" << endl;
        return 0;
    }
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') tot++;
        else tot--;
        if (tot == -1) {
            tot = 0;
            num++;
        }
    }
    cout << (num <= 1 ? "Yes" : "No") << endl;
    return 0;
}