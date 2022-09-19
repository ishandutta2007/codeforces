#include <bits/stdc++.h>

using namespace std;
long long w, n, r, ans;
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> r;
        s.clear();
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            s.insert(-x);
        }
        ans=s.size();
        int cnt=0;
        for (auto x:s) {
            if (x+r*cnt>=0) {
                ans=cnt;
                break;
            }
            cnt++;
        }
        cout << ans << "\n";
    }
    return 0;
}