#include <bits/stdc++.h>

using namespace std;
long long n, k, t[100005], dif;
vector<pair<long long, long long> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    dif=t[n]-t[1];
    for (long long i=1; i<n; i++) {
        sz.push_back({min(i, n-i), t[i+1]-t[i]});
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        long long fi=x.first, se=x.second, db=min(se, k/fi);
        dif-=db, k-=db*fi;
    }
    cout << dif << "\n";
    return 0;
}