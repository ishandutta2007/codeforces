#include <bits/stdc++.h>

using namespace std;
int n, o, e;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x%2) {
            o++;
        } else {
            e++;
        }
    }
    cout << (o%2 ? o : e) << "\n";
    return 0;
}