#include <bits/stdc++.h>

using namespace std;
int a, b, n;
int main()
{
    cin >> a >> b >> n;
    a=min(a, n), b=min(b, n);
    cout << min({a+1, b+1, a+b-n+1}) << "\n";
    return 0;
}