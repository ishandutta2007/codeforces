#include <bits/stdc++.h>

using namespace std;
long long a, b, c;
int main()
{
    cin >> a >> b >> c;
    cout << ((a-1)/c+1)*((b-1)/c+1);
    return 0;
}