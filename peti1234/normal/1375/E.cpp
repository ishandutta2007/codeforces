#include <bits/stdc++.h>

using namespace std;
const int c=1002;
long long n, t[c], pos[c], inv[c];
vector<pair<long long, long long> > sz, sol;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        t[i]*=c, t[i]+=i;
        sz.push_back({t[i], i});
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<n; i++) {
        long long se=sz[i].second;
        pos[se]=i+1, inv[i+1]=se;
    }
    //for (int i=1; i<=n; i++) cout << pos[i] << "\n";
    for (int i=1; i<=n; i++) for (int j=1; j<n; j++) {
        if (inv[j]>inv[j+1]) {
            sol.push_back({inv[j+1], inv[j]});
            swap(inv[j], inv[j+1]);
        }
    }
    cout << sol.size() << "\n";
    for (int i=0; i<sol.size(); i++) {
        cout << sol[i].first << " " << sol[i].second << "\n";
    }
    return 0;
}