#include <bits/stdc++.h>

using namespace std;
long long n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    cout << (n%2 ? 0 : 1<<(n/2)) << "\n";
    return 0;
}