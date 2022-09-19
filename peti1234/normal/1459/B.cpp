#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    cout << (n/2+1)*(n-n/2+1)*(1+n%2) << "\n";
    return 0;
}