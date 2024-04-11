#include <bits/stdc++.h>

using namespace std;
long long a, b, ans;
int main()
{
    cin >> a >> b;
    while (b%(2*a)==0) {
        a*=2, ans++;
    }
    while (b%(3*a)==0) {
        a*=3, ans++;
    }
    if (a!=b) {
        ans=-1;
    }
    cout << ans << "\n";
    return 0;
}