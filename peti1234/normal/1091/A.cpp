#include <bits/stdc++.h>

using namespace std;
int a, b, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c;
    cout << 3+3*min({a, b-1, c-2}) << "\n";
    return 0;
}