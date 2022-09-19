#include <bits/stdc++.h>

using namespace std;
int w, n;
string a, b, c;
bool baj=0;
int main()
{
    cin >> w;
    while (w--) {
        cin >> a >> b >> c;
        n=a.size(), baj=0;
        for (int i=0; i<n; i++) {
            if (a[i]!=c[i] && b[i]!=c[i]) {
                baj=1;
            }
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}