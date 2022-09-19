#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, v[c], t[c], kom[c], ans[c], add[c], ert;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        kom[i]=kom[i-1]+t[i];
    }
    for (int i=1; i<=n; i++) {
        int lo=i-1, hi=n+1, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (kom[mid]-kom[i-1]<=v[i]) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        ans[i]++, ans[hi]--;
        add[hi]+=v[i]-kom[lo]+kom[i-1];
    }
    for (int i=1; i<=n; i++) {
        ert+=ans[i];
        cout << ert*t[i]+add[i] << " ";
    }
    cout << "\n";
    return 0;
}