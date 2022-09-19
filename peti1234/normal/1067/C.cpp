#include <bits/stdc++.h>

using namespace std;
int n, x, y;
int main()
{
    cin >> n, x=n/3, y=n-2*x;
    for (int i=1; i<=x; i++) cout << 1 << " " << 2*i << "\n" << 3 << " " << 2*i << "\n";
    for (int i=1; i<=y; i++) cout << 2 << " " << 2*i+1 << "\n";
    return 0;
}