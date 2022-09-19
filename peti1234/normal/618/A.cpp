#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=20; i>=1; i--) {
        if (n>=(1<<i-1)) {
            cout << i << " ";
            n-=(1<<i-1);
        }
    }
    return 0;
}