#include <bits/stdc++.h>

using namespace std;
long long w, n, k, po[19];
vector<long long> p;
int main()
{
    ios_base::sync_with_stdio(false);
    po[0]=1;
    for (int i=1; i<=18; i++) {
        po[i]=po[i-1]*10;
    }
    cin >> w;
    while (w--) {
        cin >> n >> k;
        k++;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            p.push_back(x);
        }
        p.push_back(18);
        long long ans=0;
        for (int i=0; i<n; i++) {
            long long ert=min(k, po[p[i+1]-p[i]]-1);
            k-=ert, ans+=ert*po[p[i]];
        }
        cout << ans << "\n";
        p.clear();
    }
    return 0;
}