#include <bits/stdc++.h>

using namespace std;
int n;
long long sum=1;
int main()
{
    cin >> n, n/=2;
    for (int i=n+1; i<=2*n; i++) sum*=i;
    sum/=2;
    for (int i=1; i<=n; i++) sum/=i;
    for (int i=1; i<n; i++) sum*=i*i;
    cout << sum << "\n";
    return 0;
}