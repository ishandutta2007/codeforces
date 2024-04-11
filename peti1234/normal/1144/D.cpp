#include <bits/stdc++.h>

using namespace std;
int n, t[200005], ert, cnt;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        m[t[i]]++;
        if (m[t[i]]>cnt) {
            cnt=m[t[i]];
            ert=t[i];
        }
    }
    cout << n-cnt << "\n";
    for (int i=1; i<n; i++) {
        if (t[i]==ert && t[i+1]!=ert) {
            cout << (1+(t[i+1]>t[i])) << " " << i+1 << " " << i << "\n";
            t[i+1]=ert;
        }
    }
    for (int i=n; i>1; i--) {
        if (t[i]==ert && t[i-1]!=ert) {
            cout << (1+(t[i-1]>t[i])) << " " << i-1 << " " << i << "\n";
            t[i-1]=ert;
        }
    }
    return 0;
}