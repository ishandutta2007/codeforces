#include <bits/stdc++.h>

using namespace std;
int n, jo, t[2002];
int main()
{
    cin >> n >> t[1];
    for (int i=2; i<=2*n; i++) {
        cin >> t[i];
        if (t[i]!=t[1]) {
            jo++;
        }
    }
    if (!jo) {
        cout << -1 << "\n";
    } else {
        sort(t+1, t+2*n+1);
        for (int i=1; i<=2*n; i++) {
            cout << t[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}