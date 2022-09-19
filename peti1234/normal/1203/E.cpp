#include <bits/stdc++.h>

using namespace std;
int n, cnt, ut;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        sz.push_back(x);
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        if (ut>x) continue;
        cnt++;
        ut=max(ut+1, x-1);
    }
    cout << cnt << "\n";
    return 0;
}