#include <bits/stdc++.h>

using namespace std;
int n, k;
set<int> s;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (s.find(x)==s.end() && ans.size()<k) {
            ans.push_back(i);
        }
        s.insert(x);
    }
    if (ans.size()<k) cout << "NO\n";
    else {
        cout << "YES\n";
        for (auto x:ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}