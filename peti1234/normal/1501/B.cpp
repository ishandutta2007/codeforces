#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, kom[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            int ert=max(1, i-x+1);
            kom[ert]++, kom[i+1]--;
        }
        for (int i=1; i<=n; i++) {
            cout << (kom[i] ? 1 : 0) << " ";
            kom[i+1]+=kom[i];
            kom[i]=0;
        }
        kom[n+1]=0;
        cout << "\n";
    }
    return 0;
}