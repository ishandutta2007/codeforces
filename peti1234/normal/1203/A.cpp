#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, x, y, jo=1;
        cin >> n >> x;
        for (int i=1; i<n; i++) {
            cin >> y;
            if (abs(x-y)>1 && abs(x-y)!=n-1) jo=0;
            x=y;
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}