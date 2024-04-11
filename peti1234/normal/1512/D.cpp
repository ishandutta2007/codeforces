#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, t[c];
long long sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        n+=2, sum=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sum+=t[i];
        }
        sort(t+1, t+n+1);
        int pos=0, kim=0;
        for (int i=1; i<=n; i++) {
            long long ert=sum-2*t[i];
            int lo=0, hi=n, mid;
            while (hi-lo>1) {
                mid=(hi+lo)/2;
                if (t[mid]<ert) {
                    lo=mid;
                } else {
                    hi=mid;
                }
            }
            if (t[hi]==ert && hi!=i) {
                kim=hi, pos=i;
            }
        }
        if (!kim) {
            cout << -1 << "\n";
        } else {
            for (int i=1; i<=n; i++) {
                if (i!=kim && i!=pos) {
                    cout << t[i] << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}