#include <bits/stdc++.h>

using namespace std;
int w, n, k;
vector<int> sz;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k >> s;
        sz.clear();
        for (int i=0; i<n; i++) {
            if (s[i]=='*') {
                sz.push_back(i);
            }
        }
        int cnt=1, si=sz.size(), el=sz[0];
        for (int i=1; i<si; i++) {
            if (i+1==si || sz[i+1]-el>k) {
                cnt++;
                el=sz[i];
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}