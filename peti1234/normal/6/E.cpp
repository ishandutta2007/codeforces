#include <bits/stdc++.h>

using namespace std;
int n, k, t[100005], maxi, pos=1;
multiset<int> ert;
map<int, vector<int> > ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        ert.insert(t[i]);
        while (true) {
            int dif=0;
            auto it=ert.begin();
            dif-=*it;
            it=ert.end();
            it--;
            dif+=*it;
            if (dif<=k) break;
            ert.erase(ert.find(t[pos]));
            pos++;
        }
        int len=i-pos+1;
        maxi=max(maxi, len);
        ans[len].push_back(pos);
    }
    cout << maxi << " " << ans[maxi].size() << "\n";
    for (auto p:ans[maxi]) {
        cout << p << " " << p+maxi-1 << "\n";
    }
    return 0;
}