#include <bits/stdc++.h>

using namespace std;
long long w, n, k, cnt, ans;
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> k;
        cnt=1, ans=0;
        while (cnt<k) {
            cnt*=2, ans++;
        }
        if (cnt<n) {
            ans+=(n-cnt+k-1)/k;
        }
        cout << ans << "\n";
    }
    return 0;
}