#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, l, r, t[c], ans, dif;
multiset<int> bal, jobb;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> l >> r;
        ans=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        if (l>r) {
            swap(l, r);
            reverse(t+1, t+n+1);
        }
        dif=(r-l)/2;
        for (int i=1; i<=l; i++) {
            bal.insert(t[i]);
        }
        for (int i=l+1; i<=n; i++) {
            if (bal.find(t[i])!=bal.end()) {
                bal.erase(bal.find(t[i]));
            } else {
                if (dif && jobb.find(t[i])!=jobb.end()) {
                    ans++;
                    dif--;
                    jobb.erase(jobb.find(t[i]));
                } else {
                    jobb.insert(t[i]);
                }
            }
        }
        int sb=bal.size(), sj=jobb.size();
        ans+=(sb+sj)/2+dif;
        //cout << "valasz: ";
        cout << ans << "\n";
        bal.clear(), jobb.clear();
    }
    return 0;
}