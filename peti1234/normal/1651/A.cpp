#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, n;
    cin >> w;
    while (w--) {
        cin >> n;
        cout << (1<<n)-1 << "\n";
    }
    return 0;
}