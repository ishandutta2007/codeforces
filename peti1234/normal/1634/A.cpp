#include <bits/stdc++.h>

using namespace std;
int w, n, k;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k >> s;
        if (k==0) {
            cout << 1 << "\n";
        } else {
            bool jo=0;
            for (int i=0; i<n; i++) {
                if (s[i]!=s[n-i-1]) jo=1;
            }
            cout << (jo ? 2 : 1) << "\n";
        }
    }
    return 0;
}