#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w, n;
    cin >> w;
    while (w--) {
        cin >> n;
        cout << max(4-n, n%2) << "\n";
    }
    return 0;
}