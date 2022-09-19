#include <bits/stdc++.h>

using namespace std;
long long n, ans, po=1;
int main()
{
    cin >> n;
    for (int i=1; i<=n-3; i++) po*=4;
    cout << po*24+(n-3)*9*po << "\n";
    return 0;
}