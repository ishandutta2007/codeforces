#include <bits/stdc++.h>

using namespace std;
long long w, n, ans, f, mod=1e9+7;
vector<int> sz={0, 1, 2, 3, 2, 5, 1, 7, 2, 3, 1, 11, 1, 13, 1, 1, 2, 17, 1, 19, 1, 1, 1, 23, 1, 5, 1, 3, 1, 29, 1, 31, 2, 1, 1, 1, 1, 37, 1, 1, 1, 41, 1, 43, 1, 1, 1, 47, 1, 7, 1, 1, 1, 53, 1, 1, 1, 1, 1, 59};
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        ans=0, f=1;
        for (int i=1; f<=n; i++) {
            ans+=n/f;
            if (n/f>=sz[i]) {
                f*=sz[i];
            } else {
                break;
            }
        }
        cout << ans%mod << "\n";
    }
    return 0;
}