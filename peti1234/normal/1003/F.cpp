#include <bits/stdc++.h>

using namespace std;
const int c=305;
int n, k, sum, cnt, t[c], ert[c], pref[c], lcp[c][c], ans;
map<string, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        if (m.find(s)==m.end()) {
            m[s]=++cnt;
        }
        t[i]=m[s];
        ert[i]=s.size();
        //cout << "fontos " << i << " " << t[i] << " " << ert[i] << "\n";
        pref[i]=pref[i-1]+ert[i];
    }
    for (int i=n; i>=1; i--) {
        for (int j=n; j>=1; j--) {
            lcp[i][j]=(t[i]==t[j] ? lcp[i+1][j+1]+1 : 0);
        }
    }

    for (int pos=1; pos<=n; pos++) {
        for (int len=1; pos+len<=n+1; len++) {
            int sum=pref[pos+len-1]-pref[pos-1], cnt=0;
            int s=1;
            while (s<=n) {
                if (lcp[s][pos]>=len) {
                    cnt++;
                    s+=len;
                } else {
                    s++;
                }
            }

            if (cnt>1) ans=max(ans, cnt*(sum-1));
            //cout << "fontos " << pos << " " << len << " " << sum << " " << cnt << "\n";
        }
    }
    cout << pref[n]+n-1-ans << "\n";
    return 0;
}