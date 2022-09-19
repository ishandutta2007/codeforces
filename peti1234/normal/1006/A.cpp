#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        cout << x-1+x%2 << " ";
    }
    cout << "\n";
    return 0;
}