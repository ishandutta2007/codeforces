#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
char s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> (s + 1);
    n = strlen(s + 1);
    int cur = 0;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int found = cur;
        for (int j = cur + 1; j + 1 < i; j++) {
            if ((i - j) % 2 == 0) {
                int z = i + j >> 1;
                if (s[i] == s[j] && s[j] == s[z]) {
                    found = j;
                }
            }
        }
        cur = found;
        res += cur;
    }
    cout << res << endl;
    return 0;
}