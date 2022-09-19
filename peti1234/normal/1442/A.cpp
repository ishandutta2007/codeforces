#include <bits/stdc++.h>

using namespace std;
const int c=30002;
int w, t[c], n;
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, sum=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=n-1; i>=1; i--) {
            sum+=max(0, t[i]-t[i+1]);
        }
        if (sum>t[1]) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}