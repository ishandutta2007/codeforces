#include <bits/stdc++.h>
using namespace std;

int main() {
    char c; cin >> c;
    int j; cin >> j, --j;
    int i = c-'a';
    
    int ans = 0;
    for (int ni = i-1; ni <= i+1; ni++) for (int nj = j-1; nj <= j+1; nj++) {
        if (ni != i || nj != j) {
            if (0 <= ni && ni < 8 && 0 <= nj && nj < 8) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
}