#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int w;
long long n, m, pos, sum, t[c], k[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> m, pos=1, sum=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=m; i++) {
            cin >> k[i];
        }
        sort(t+1, t+n+1), reverse(t+1, t+n+1);
        for (int i=1; i<=n; i++) {
            if (pos<=t[i]) {
                sum+=k[pos], pos++;
            } else {
                sum+=k[t[i]];
            }
        }
        cout << sum << "\n";
    }
    return 0;
}