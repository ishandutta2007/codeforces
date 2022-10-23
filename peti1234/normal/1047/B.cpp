#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, maxi=0;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        maxi=max(maxi, x+y);
    }
    cout << maxi << "\n";
    return 0;
}