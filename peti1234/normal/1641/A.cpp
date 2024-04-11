#include <bits/stdc++.h>

using namespace std;
long long w, n, x;
map<long long, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> x;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            m[x]++;
        }
        int cnt=n;
        for (auto p:m) {
            int ert=p.first;
            while (m[ert]>0 && m[ert*x]>0) {
                m[ert]--, m[ert*x]--;
                cnt-=2;
            }
        }
        m.clear();
        cout << cnt << "\n";
    }
    return 0;
}