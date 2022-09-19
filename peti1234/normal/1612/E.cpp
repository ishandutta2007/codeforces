#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, t[c][21], ert, len;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        t[a][b]++;
    }
    for (int s=1; s<=20; s++) {
        vector<pair<int, int> > r;
        for (int i=1; i<=200000; i++) {
            int ert=0;
            for (int j=1; j<=20; j++) {
                ert+=t[i][j]*min(j, s);
            }
            if (ert) r.push_back({ert, i});
        }
        sort(r.rbegin(), r.rend());
        if (s>r.size()) {
            break;
        }
        int sum=0;
        for (int i=0; i<s; i++) {
            sum+=r[i].first;
        }
        if (len==0 || sum*len>ert*s) {
            ert=sum, len=s;
            ans.clear();
            for (int i=0; i<s; i++) ans.push_back(r[i].second);
        }
    }
    cout << len << "\n";
    for (auto x:ans) cout << x << " ";
    cout << "\n";
    return 0;
}