#include <bits/stdc++.h>

using namespace std;
int n, k, cnt;
vector<pair<int, int> > sz;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz.push_back({a, -1});
        sz.push_back({b, 1});
    }
    sort(sz.begin(), sz.end());
    for (auto p:sz) {
        int a=p.first, b=p.second;
        cnt-=b;
        if (b==-1 && cnt==k || b==1 && cnt==k-1) {
            ans.push_back(a);
        }
    }
    int si=ans.size();
    cout << si/2 << "\n";
    for (int i=0; i<si; i+=2) {
        cout << ans[i] << " " << ans[i+1] << "\n";
    }
    return 0;
}