#include <bits/stdc++.h>

using namespace std;
int w, n, d, k, g;
string s;
map<pair<int, int>, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        cin >> s;
        d=0, k=0;
        m.clear();
        for (int i=0; i<n; i++) {
            if (s[i]=='D') {
                d++;
            }
            if (s[i]=='K') {
                k++;
            }
            g=__gcd(d, k);
            int ert=m[{d/g, k/g}]+1;
            cout << ert << " ";
            m[{d/g, k/g}]=ert;
        }
        cout << "\n";
    }
    return 0;
}