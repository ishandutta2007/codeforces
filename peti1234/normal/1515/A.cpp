#include <bits/stdc++.h>

using namespace std;
const int c=102;
int w, n, x, t[c], sum, pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> x;
        sum=0, pos=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sum+=t[i];
            if (sum==x) {
                pos=i;
            }
        }
        if (pos==n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if (pos) {
                swap(t[pos], t[pos+1]);
            }
            for (int i=1; i<=n; i++) {
                cout << t[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}