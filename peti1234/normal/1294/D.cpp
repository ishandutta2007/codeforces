#include <bits/stdc++.h>

using namespace std;
int n, x, db=1, mini, ans;
int t[400001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        int b=a%x;
        t[b]++;
        while(t[mini]>=db) {
            mini++, ans++;
            if (mini==x) db++, mini=0;
        }
        cout << ans << "\n";
    }
    return 0;
}