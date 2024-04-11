#include <bits/stdc++.h>

using namespace std;
map<int, int> m;
void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        while (x%10!=0 && x%10!=2) x+=x%10;
        if (x%10==0) m[x]++;
        else {
            m[x%20]++;
        }
    }
    cout << (m.size()==1 ? "Yes" : "No") << "\n";
    m.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}