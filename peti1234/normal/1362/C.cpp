#include <bits/stdc++.h>

using namespace std;
long long w, n, ans;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, ans=2*n;
        while(n>0) ans-=n%2, n/=2;
        cout << ans << "\n";
    }
    return 0;
}