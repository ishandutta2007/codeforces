#include <bits/stdc++.h>

using namespace std;
const int c=300005;
long long w, n, pref[2], x, ans;
multiset<long long> s[2];
map<long long, int> m[2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        s[0].insert(0);
        m[0][0]=1;
        for (int i=1; i<=n; i++) {
            cin >> x;
            if (i%2==0) x*=-1;
            pref[0]+=x, pref[1]-=x;
            for (int j=0; j<2; j++) {
                ans+=m[j][pref[j]];
                if ((i-j)%2) {
                    while (s[j].size()>0) {
                        auto it=s[j].end();
                        it--;
                        if (pref[j]<*it) {
                            m[j][*it]--;
                            s[j].erase(it);
                        } else break;
                    }
                } else {
                    while (s[j].size()>0) {
                        auto it=s[j].begin();
                        if (pref[j]>*it) {
                            m[j][*it]--;
                            s[j].erase(it);
                        } else break;
                    }
                    s[j].insert(pref[j]);
                    m[j][pref[j]]++;
                }
            }
        }
        cout << ans << "\n";
        ans=0, pref[0]=0, pref[1]=0, x=0;
        s[0].clear(), s[1].clear();
        m[0].clear(), m[1].clear();
    }
    return 0;
}