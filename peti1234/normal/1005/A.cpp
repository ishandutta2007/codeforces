#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int el=0;
    vector<int> ans;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if (x<=el) {
            ans.push_back(el);
        }
        el=x;
    }
    ans.push_back(el);

    cout << ans.size() << "\n";
    for (auto x:ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}