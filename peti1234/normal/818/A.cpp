#include <bits/stdc++.h>

using namespace std;
long long n, k;
int main()
{
    cin >> n >> k;
    long long x=n/(2*k+2);
    cout << x << " " << k*x << " " << n-(k+1)*x << "\n";
    return 0;
}