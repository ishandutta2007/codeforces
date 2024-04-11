#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, t[c], db[c];
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            db[t[i]]++;
        }
        int mex=0;
        set<int>s;
        for (int i=1; i<=n; i++) {
            s.insert(t[i]);
            db[t[i]]--;
            while (s.find(mex)!=s.end()) mex++;
            if (db[mex]==0) {
                ans.push_back(mex);
                mex=0;
                s.clear();
            }
        }
        cout << ans.size() << "\n";
        for (auto x:ans) {
            cout << x << " ";
        }
        cout << "\n";
        ans.clear();
    }
    return 0;
}
/*
1
5
1 0 2 0 3
*/