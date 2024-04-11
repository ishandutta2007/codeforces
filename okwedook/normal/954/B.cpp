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
    for (int i = n / 2 - 1; i > 0; --i) {
        bool cr = false;
        for (int j = 0, k = i + 1; j <= i; ++j, ++k)
            if (s[j] != s[k]) cr = true;
        if (cr) continue;
        ans = n - i;  
        break;
    }
    cout << ans;
    return 0;
}