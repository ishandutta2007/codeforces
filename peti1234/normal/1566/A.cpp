#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w, n, s;
    cin >> w;
    while (w--) {
        cin >> s >> n;
        s=s/2+1;
        cout << n/s << "\n";
    }
    return 0;
}