#include <bits/stdc++.h>

using namespace std;
long long m=1000000007, f=1, p=1, n;
int main()
{
    cin >> n;
    for (int i=2; i<=n; i++) p*=2, p%=m, f*=i, f%=m;
    cout << (f+m-p)%m;
    return 0;
}