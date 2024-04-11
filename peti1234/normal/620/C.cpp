#include <bits/stdc++.h>

using namespace std;
set<int> s;
int n, x;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    ans.push_back(1);
    for (int i=1; i<=n; i++) {
        cin >> x;
        if (s.count(x)) {
            ans.push_back(i);
            ans.push_back(i+1);
            s.clear();
        } else {
            s.insert(x);
        }
    }
    if (ans.back()==1) {
        cout << -1 << "\n";
        return 0;
    }
    ans.pop_back();
    ans.back()=n;
    int si=ans.size();
    cout << si/2 << "\n";
    for (int i=0; i<si; i+=2) {
        cout << ans[i] << " " << ans[i+1] << "\n";
    }
    return 0;
}