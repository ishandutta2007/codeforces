#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;
char s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> (s + 1);
    n = strlen(s + 1);
    long long numW = 0, numWO = 0;
    long long res = 0;
    for (int l = 1, r = 1; l <= n; l = r) {
        while (r <= n && s[l] == s[r]) r++;
        if (s[l] == 'o') {
            numWO += numW * (r - l);
        } else {
            res += numWO * (r - l - 1);
            numW += (r - l - 1);
        }
    }
    cout << res << endl;
    return 0;
}