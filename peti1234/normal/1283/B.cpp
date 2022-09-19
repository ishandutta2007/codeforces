#include <bits/stdc++.h>

using namespace std;
int w;
long long n, k, ans;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> k;
        ans=n/k*k;
        n-=ans;
        cout << ans+min(k/2, n) << "\n";
    }
    return 0;
}