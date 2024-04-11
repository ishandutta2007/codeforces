#include <bits/stdc++.h>

using namespace std;
int n, x;
int main()
{
    cin >> n;
    n*=2;
    x=sqrt(n);
    cout << (x*x+x==n ? "YES" : "NO") << "\n";
    return 0;
}