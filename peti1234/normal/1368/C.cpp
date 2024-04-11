#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin >> n;
    cout << 4+3*n << "\n";
    cout << "0 0\n0 1\n1 0\n1 1\n";
    for (int i=1; i<=n; i++) cout << i+1 << " " << i << "\n" << i << " " << i+1 << "\n" << i+1 << " " << i+1 << "\n";
    return 0;
}