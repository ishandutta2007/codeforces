#include <bits/stdc++.h>

using namespace std;
const int c=30000005;
int n, k, cnt=1, bal[c], jobb[c], db[c], pref;
long long ans;
void add(int x) {
    int pos=1;
    for (int i=29; i>=0; i--) {
        if (x & (1<<i)) {
            if (!jobb[pos]) jobb[pos]=++cnt;
            pos=jobb[pos];
        } else {
            if (!bal[pos]) bal[pos]=++cnt;
            pos=bal[pos];
        }
        db[pos]++;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    add(0);
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        pref=pref^x;
        add(pref);
        int xo=0, pos=1;
        for (int j=29; j>=0; j--) {
            if (xo+(1<<j)>=k) {
                if (pref & (1<<j)) ans+=db[bal[pos]], pos=jobb[pos];
                else ans+=db[jobb[pos]], pos=bal[pos];
            } else {
                if (pref & (1<<j)) pos=bal[pos];
                else pos=jobb[pos];
                xo+=(1<<j);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
1 2
1
*/