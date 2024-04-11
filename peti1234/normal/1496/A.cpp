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
        bool jo=(2*k<n);
        for (int i=0; i<k; i++) {
            if (s[i]!=s[n-1-i]) {
                jo=0;
            }
        }
        cout << (jo? "Yes" : "No") << "\n";
    }
    return 0;
}