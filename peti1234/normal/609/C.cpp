#include <bits/stdc++.h>

using namespace std;
int n, sum, kis, nagy, x, y, t[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i];
    }
    kis=sum/n, nagy=(sum+n-1)/n;
    for (int i=1; i<=n; i++) {
        x+=max(0, kis-t[i]);
        y+=max(0, t[i]-nagy);
    }
    cout << max(x, y) << "\n";
    return 0;
}