#include <bits/stdc++.h>

using namespace std;
const int c=1000005;
int n, kp[c], t[c];
vector<int> fr={0}, pr[c];
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=2; i<=c; i++) {
        if (!kp[i]) {
            for (int j=i; j<=c; j+=i) {
                if (!kp[j]) {
                    kp[j]=i;
                }
            }
        }
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        vector<int> sz;
        int s=t[i];
        while (s>1) {
            sz.push_back(kp[s]);
            s/=kp[s];
        }
        if (c=='*') {
            for (auto x:sz) {
                pr[x].push_back(i);
            }
        }
        if (c=='/') {
            int mini=i;
            for (auto x:sz) {
                if (pr[x].size()>0) {
                    mini=min(mini, pr[x].back());
                    pr[x].pop_back();
                } else {
                    mini=0;
                }
            }
            while (fr.size()>0 && fr.back()>=mini) {
                fr.pop_back();
            }
        }
        ans+=fr.size();
        fr.push_back(i);
    }
    cout << ans << "\n";
    return 0;
}