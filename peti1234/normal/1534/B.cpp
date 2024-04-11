#include <bits/stdc++.h>

using namespace std;
const int c=500002;
long long w, n, t[c], sum, o=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        t[0]=0, t[n+1]=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sum=0;
        for (int i=1; i<=n+1; i++) {
            sum+=abs(t[i]-t[i-1]);
        }
        for (int i=1; i<=n; i++) {
            sum-=max(o, t[i]-max(t[i-1], t[i+1]));
        }
        cout << sum << "\n";
    }
    return 0;
}