#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int w, n, t[c];
vector<int> oszt[c], sz[c];
set<int> pr;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int i=2; i<c; i++) {
        if (oszt[i].size()==0) {
            for (int j=i; j<c; j+=i) {
                oszt[j].push_back(i);
            }
        }
    }
    while (w--) {
        cin >> n;
        int lnko=0;
        for (int i=0; i<n; i++) {
            cin >> t[i];
            lnko=__gcd(lnko, t[i]);
        }
        for (int i=0; i<n; i++) {
            t[i]/=lnko;
            for (auto x:oszt[t[i]]) {
                pr.insert(x);
                sz[x].push_back(i);
            }
        }
        int maxi=0, len=0;
        for (auto s:pr) {
            len=1, maxi=max(maxi, len);
            for (int i=1; i<sz[s].size(); i++) {
                if (sz[s][i]>sz[s][i-1]+1) {
                    len=0;
                }
                len++;
                maxi=max(maxi, len);
            }
            if (sz[s].back()==n-1) {
                for (int i=0; i<sz[s].size(); i++) {
                    if (sz[s][i]==i) {
                        len++;
                    }
                }
                maxi=max(maxi, len);
            }
        }
        cout << maxi << "\n";

        for (auto s:pr) {
            sz[s].clear();
        }
        pr.clear();
    }
    return 0;
}