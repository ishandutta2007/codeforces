#include <bits/stdc++.h>

using namespace std;
long long n, h, t[200005], sum, maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> h >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        t[i]*=-1;
        sum+=t[i];
        maxi=max(maxi, sum);
    }
    if (sum<=0 && h-maxi>0) {
        cout << -1 << "\n";
        return 0;
    }
    long long db=(h>maxi ? (h-maxi+sum-1)/sum : 0);
    h-=db*sum;
    for (int i=1; i<=n; i++) {
        h-=t[i];
        if (h<=0) {
            cout << db*n+i << "\n";
            return 0;
        }
    }
    return 0;
}
/*
1000 6
-100 -200 -300 125 77 -4
*/