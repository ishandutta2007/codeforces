#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, mini, pref[c];
bool calc(int a, int b) {
    int x=pref[a]+pref[n]-pref[b], y=b-a-(pref[b]-pref[a]);
    mini=min(mini, max(x, y));
    return (x>=y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        string s;
        cin >> s;
        n=s.size();
        mini=n;
        for (int i=1; i<=n; i++) {
            pref[i]=(pref[i-1]+(s[i-1]=='1'));
        }
        calc(0, 0);
        for (int kezd=0; kezd<n; kezd++) {
            int lo=kezd, hi=n, mid;
            calc(kezd, kezd), calc(kezd, n);
            while (hi-lo>1) {
                mid=(hi+lo)/2;
                if (calc(kezd, mid)) {
                    lo=mid;
                } else {
                    hi=mid;
                }
            }
        }
        cout << mini << "\n";
    }
    return 0;
}