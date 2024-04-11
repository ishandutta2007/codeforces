#include <bits/stdc++.h>

using namespace std;
int n, maxi;
map<int, int> m;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    for (auto p:m) {
        sz.push_back(p.second);
    }
    sort(sz.rbegin(), sz.rend());
    for (int kezd=1; kezd<=n; kezd++) {
        int ert=kezd, sum=0;
        for (int i=0; i<sz.size(); i++) {
            if (sz[i]>=ert) sum+=ert;
            else break;
            if (ert%2) break;
            else ert/=2;
        }
        maxi=max(maxi, sum);
    }
    cout << maxi << "\n";
    return 0;
}