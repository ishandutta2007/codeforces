#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int inf = 1e9 + 7;

void checkmin(int &a, int b) {
    if (b < a) a = b;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n;
    for (int i = 1; i < n; ++i)
        if (s[i] != s[i - 1]) {
            --ans;
            ++i;
        }
    cout << ans;
    return 0;
}