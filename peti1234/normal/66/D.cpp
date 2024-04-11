#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin >> n;
    if (n<3) cout << -1;
    else {
        cout << "10\n15\n";
        for (int i=1; i<=n-2; i++) cout << 6*i << "\n";
    }
    return 0;
}