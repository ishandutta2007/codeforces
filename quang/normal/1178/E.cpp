#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

char s[N];
int n;
bool choose[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> (s + 1);
    n = strlen(s + 1);
    int l, r;
    for (l = 1, r = n; l + 1 < r - 1; l += 2, r -= 2) {
        if (s[l] == s[r]) {
            choose[l] = choose[r] = 1;
        } else if (s[l] == s[r - 1]) {
            choose[l] = choose[r - 1] = 1;
        } else if (s[l + 1] == s[r]) {
            choose[l + 1] = choose[r] = 1; 
        } else {
            choose[l + 1] = choose[r - 1] = 1;
        }
    }
    if (l <= r) choose[l] = 1;
    for (int i = 1; i <= n; i++) {
        if (choose[i]) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}