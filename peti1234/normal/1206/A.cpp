#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int i=0; i<2; i++) {
        int n, x, maxi=0;
        cin >> n;
        while (n--) {
            cin >> x;
            maxi=max(maxi, x);
        }
        cout << maxi << " ";
    }
    return 0;
}