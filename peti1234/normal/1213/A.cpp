#include <bits/stdc++.h>

using namespace std;
int n, o, e;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        if (x%2) o++;
        else e++;
    }
    cout << min(o, e) << "\n";
    return 0;
}