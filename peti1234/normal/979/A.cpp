#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n, n++;
    if (n==1) cout << 0;
    else if (n%2) cout << n;
    else cout << n/2;
    return 0;
}