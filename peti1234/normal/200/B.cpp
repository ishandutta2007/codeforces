#include <bits/stdc++.h>

using namespace std;
double n, x, sum;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {cin >> x, sum+=x;}
    cout << sum/n << "\n";
    return 0;
}