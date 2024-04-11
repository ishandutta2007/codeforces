#include <bits/stdc++.h>

using namespace std;
long long w, n, k, sum, t[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        sum=0;
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sum+=t[i];
        }
        sort(t+1, t+n+1);
        long long mini=max((long long) 0, sum-k);
        for (long long i=1; i<n; i++) {
            sum-=t[n+1-i]-t[1];
            if (sum<=k) mini=min(mini, i);
            else mini=min(mini, i+(sum-k+i)/(i+1));
        }
        cout << mini << "\n";
    }
    return 0;
}