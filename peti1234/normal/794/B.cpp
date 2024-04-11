#include <bits/stdc++.h>

using namespace std;
long double h;
long long n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> h;
    cout.precision(10);
    for (long double i=1; i<n; i++) {
        cout << sqrt(i/n)*h << " ";
    }
    return 0;
}