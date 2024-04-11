#include <bits/stdc++.h>

using namespace std;
int n, t[100005], sum, cnt, ert;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        sum+=t[i];
    }
    for (int i=1; i<=n; i++) {
        if (2*ert+t[i]<=sum) {
            ert+=t[i];
            cnt++;
        } else break;
    }
    cout << cnt << " " << n-cnt << "\n";
    return 0;
}