#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        int n; cin >> n;
        map<int, int> mcount;
        for(int i = 0; i < n; ++i) {
            int x; cin >> x;
            mcount[x]++;
        }

        vector<int> pcount(n+2, 0), psum(n+2, 0);
        for(auto p : mcount) pcount[p.second] += 1;

        for(int i = 1; i < psum.size(); ++i) psum[i] = (psum[i-1] + pcount[i]*i);
        
        int ans = n, curcost = 0, curcount = 0;
        for(int i = pcount.size() - 1; i > 0; --i) {
            curcost += pcount[i] * i;
            curcount += pcount[i];
            ans = min(ans, psum[i-1] + curcost - i * curcount);
        }

        cout << ans << endl;
    }

    return 0;
}