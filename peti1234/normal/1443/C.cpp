#include <bits/stdc++.h>

using namespace std;
const int c=200002, p=1e9+1;
long long w, n, a[c], b[c], lo, hi, mid, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin  >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
        }
        lo=0, hi=p;
        while(hi-lo>1) {
            mid=(hi+lo)/2, sum=0;
            for (int i=1; i<=n; i++) {
                if (a[i]>mid) sum+=b[i];
            }
            if (sum>mid) lo=mid;
            else hi=mid;
        }
        cout << hi << "\n";
    }
    return 0;
}