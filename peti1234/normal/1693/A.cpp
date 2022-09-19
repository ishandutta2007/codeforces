#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long w, n;
    cin >> w;
    while (w--) {
        cin >> n;
        long long sum=0, baj=0, x;
        for (int i=1; i<=n; i++) {
            cin >> x;
            if (sum==0 && i>1 && x!=0) {
                baj=1;
            }
            sum+=x;
            if (sum<0) baj=1;
        }
        if (sum!=0) {
            baj=1;
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}