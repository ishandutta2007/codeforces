#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n=0, o=0, e=0, jo=1;
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            if (x%2) {
                if (x<o) jo=0;
                o=x;
            } else {
                if (x<e) jo=0;
                e=x;
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}