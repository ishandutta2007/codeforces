#include <bits/stdc++.h>

using namespace std;
int n, k, ans;
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        x%=k;
        int s=(k-x)%k;
        if (m[s]>0) {
            m[s]--, ans+=2;
        } else {
            m[x]++;
        }
    }
    cout << ans << "\n";
    return 0;
}