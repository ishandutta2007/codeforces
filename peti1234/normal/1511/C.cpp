#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, q, pos, t[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=q; i++) {
        int ert;
        cin >> ert;
        for (int i=1; i<=n; i++) {
            if (t[i]==ert) {
                pos=i;
                break;
            }
        }
        cout << pos << " ";
        for (int i=pos; i>1; i--) {
            swap(t[i], t[i-1]);
        }
    }
    return 0;
}