#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i=n; i>=1; i--) {
        if (n%i==0 && i<=n/i) {
            cout << i << " " << n/i << endl;
            return 0;
        }
    }
    return 0;
}