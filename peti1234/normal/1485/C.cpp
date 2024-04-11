#include <bits/stdc++.h>

using namespace std;
long long w, a, b, ans, o=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        ans=0;
        for (long long i=1; i<=100000; i++) {
            ans+=max(o, min((a-i)/i-i, b-i));
        }
        cout << ans << "\n";
    }
    return 0;
}