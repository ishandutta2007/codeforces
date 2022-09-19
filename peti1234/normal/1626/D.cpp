#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, t[c], el[c], kov[c];
int main()
{
    ios_base::sync_with_stdio(false);
    el[0]=kov[0]=1;
    for (int i=1; i<c; i++) {
        if (__builtin_popcount(i)==1) el[i]=kov[i]=i;
        else {
            el[i]=el[i-1];
            kov[i]=2*el[i];
        }
    }
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        sort(t+1, t+n+1);
        set<int> s;
        s.insert(0), s.insert(n), s.insert(n+1);
        for (int i=1; i<n; i++) {
            if (t[i]!=t[i+1]) {
                s.insert(i);
            }
        }
        int ans=kov[n]+2;
        for (auto x:s) {
            if (x>n) continue;
            int ert=kov[n-x], cel=x-el[x], dif=x;
            auto p=s.lower_bound(cel);
            if (0<=*p && *p<=x) {
                dif=min(dif, *p);
            }
            p=s.upper_bound(x-cel);
            p--;
            if (0<=*p && *p<=x) {
                dif=min(dif, x-*p);
            }
            if (x==el[x] && x>1 && s.find(x/2)!=s.end()) {
                dif=x/2;
            }
            ert+=kov[dif]+kov[x-dif];
            ans=min(ans, ert);
        }
        cout << ans-n << "\n";


    }
    return 0;
}
/*
1
3
1 2 3
*/