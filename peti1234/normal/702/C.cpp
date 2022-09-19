#include <bits/stdc++.h>

using namespace std;
long long n, m, maxi=0, sok=1e10;
set<long long> s;
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sz.push_back(x);
    }
    for (int i=1; i<=m; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    s.insert(-sok), s.insert(sok);
    for (auto x:sz) {
        auto it=s.upper_bound(x), it2=it;
        it2--;
        maxi=max(maxi, min(abs(x-*it), abs(x-*it2)));
    }
    cout << maxi << "\n";
    return 0;
}