#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool more = true;
    for (int i = k; i < n; i++) {
        if (s[i] < s[i - k]) break;
        if (s[i] > s[i - k]) more = false;
    }
    if (!more) {
        for (int j = k - 1; j >= 0; j--) {
            if (s[j] != '9') {
                s[j]++;
                break;
            }
            s[j] = '0';
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            s[j] = s[i];
        }
    }
    cout << s.size() << "\n";
    cout << s << "\n";
    return 0;
}