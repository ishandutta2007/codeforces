#include <bits/stdc++.h>

using namespace std;
long long a, b, c, d, ans;
int main()
{
    cin >> a >> b >> c >> d;
    ans=(c-a+1)*(d-b+1)+1;
    cout << ans/2 << "\n";
    return 0;
}