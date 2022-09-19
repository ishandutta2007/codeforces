#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, t[c], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sum+=t[i];
        }
        sort(t+1, t+n+1);
        if (sum+(n-2)*t[n]<0 || sum+(n-2)*t[1]>0) {
            cout << "INF\n";
        } else {
            if (n==2) {
                cout << t[1]*t[2] << "\n";
            } else {
                long long maxi=-1e18, ert=t[1]*t[n], spec=t[1]+t[n], kis=sum-spec, nagy=0;
                for (int i=2; i<n; i++) {
                    maxi=max(maxi, ert+kis*t[1]+nagy*t[n]-t[i]*((n-i)*t[1]+(i-2)*t[n]+sum));
                    kis-=t[i], nagy+=t[i];
                }
                cout << maxi << "\n";
            }
        }

        sum=0;
    }
    return 0;
}
/*
1
3
3 -1 -2
*/