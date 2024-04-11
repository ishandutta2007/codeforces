#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, a=0, b=0;
        cin >> n;
        while (n--) {
            int x;
            cin >> x;
            if (x%2) a++;
            else b++;
        }
        cout << min(a, b) << "\n";
    }
    return 0;
}