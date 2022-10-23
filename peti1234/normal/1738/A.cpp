#include <bits/stdc++.h>

using namespace std;
long long n, sum, t[100005];
vector<long long> a, b;
void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sum+=x;
        if (t[i]==0) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.rbegin(), a.rend()), sort(b.rbegin(), b.rend());
    int sa=a.size(), sb=b.size();
    for (int i=0; i<min(sa, sb); i++) {
        sum+=a[i], sum+=b[i];
    }
    if (sa==sb) {
        sum-=min(a[sa-1], b[sb-1]);
    }
    //cout << "valasz...... ";
    cout << sum << "\n";
    a.clear(), b.clear();
    sum=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}