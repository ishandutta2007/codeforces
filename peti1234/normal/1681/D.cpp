#include <bits/stdc++.h>

using namespace std;
long long x, n;
map<long long, int> m;
long long solve(long long ert) {
    if (m.find(ert)==m.end()) {
        long long db=0, s=ert;
        vector<int> sz;
        while (s) {
            sz.push_back(s%10);
            db++;
            s/=10;
        }
        if (db==n) {
            return 0;
        }
        long long mini=100;
        for (auto p:sz) {
            if (p>1) {
                mini=min(mini, solve(ert*p)+1);
            }
        }
        m[ert]=mini;
    }
    return m[ert];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    long long ans=solve(x);
    cout << (ans>=100 ? -1 : ans) << "\n";
}