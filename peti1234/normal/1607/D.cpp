#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, t[c];
vector<int> bl, re;
bool baj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            if (c=='B') bl.push_back(t[i]);
            else re.push_back(t[i]);
        }
        sort(bl.begin(), bl.end());
        for (int i=0; i<bl.size(); i++) {
            if (bl[i]<=i) baj=1;
        }
        sort(re.rbegin(), re.rend());
        for (int i=0; i<re.size(); i++) {
            if (re[i]>n-i) baj=1;
        }
        cout << (baj ? "NO" : "YES") << "\n";
        baj=0;
        bl.clear(), re.clear();
    }
    return 0;
}