#include <bits/stdc++.h>

using namespace std;
long long n, q, x, y, sum, kis=1e18, nagy, o=0;
multiset<long long> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long p;
        cin >> p;
        sum+=p;
        s.insert(p);
        kis=min(kis, p);
        nagy=max(nagy, p);
    }
    cin >> q;
    while (q--) {
        cin >> x >> y;
        long long p=x+y;
        //cout << "valasz .............. ";
        if (x>=nagy) {
            cout << max(x-nagy, p-sum) << "\n";
        } else if (x<=kis) {
            cout << max(o, y+kis-sum) << "\n";
        } else {
            long long ans=2e18;
            auto lb=s.lower_bound(x);
            ans=max(o, y+*lb-sum);
            lb--;
            ans=min(ans, max(x-*lb, p-sum));
            cout << ans << "\n";
        }
    }
    return 0;
}