#include <bits/stdc++.h>

using namespace std;
long long n, d, e, mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> d >> e, mini=n%d;
    e*=5;
    while(n>=e) {
        n-=e, mini=min(mini, n%d);
    }
    cout << mini << "\n";
    return 0;
}