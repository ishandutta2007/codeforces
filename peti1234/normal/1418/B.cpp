#include <bits/stdc++.h>

using namespace std;
const int c=102;
int w, n, t[c], v[c], pos;
vector<int> sz;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, sz.clear(), pos=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=n; i++) {
            cin >> v[i];
            if (v[i]==0) sz.push_back(t[i]);
        }
        sort(sz.rbegin(), sz.rend());
        for (int i=1; i<=n; i++) {
            if (v[i]) cout << t[i] << " ";
            else cout << sz[pos] << " ", pos++;
        }
        cout << "\n";
    }
    return 0;
}