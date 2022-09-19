#include <bits/stdc++.h>

using namespace std;
long long n, k, t[200005], o=0, lo=0, hi, mid;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    hi=n+1;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    reverse(t+1, t+n+1);
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        long long sum=0;
        for (int i=1; i<=n; i++) {
            sum+=max(o, t[i]-(i-1)/mid);
        }
        if (sum>=k) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    cout << (hi==n+1 ? -1 : hi) << "\n";
    return 0;
}