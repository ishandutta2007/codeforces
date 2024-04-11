#include <bits/stdc++.h>

using namespace std;
int w, n, ut, s=(1<<30)-1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> ut;
        cout << 0 << " ";
        for (int i=1; i<n; i++) {
            int x;
            cin >> x;
            ut=x+((s-x)&ut);
            cout << ut-x << " ";
        }
        cout << "\n";
    }
    return 0;
}