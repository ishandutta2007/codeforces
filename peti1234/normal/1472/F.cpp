#include <bits/stdc++.h>

using namespace std;
int w, n, m, a, b, baj;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> m >> n, a=0, b=0, baj=n%2;
        sz.clear();
        for (int i=1; i<=n; i++) {
            int a, b; cin >> a >> b;
            sz.push_back({b, a});
        }
        sort(sz.begin(), sz.end());
        for (int i=0; i<n; i++) {
            int x=sz[i].first, y=sz[i].second, z=(x+y)%2;
            if (z) a++;
            else b++;
            int dif=abs(a-b);
            if (i && x==sz[i-1].first && dif) {
                baj=1;
            }
            if (dif>1) {
                baj=1;
            }
        }
        cout << (baj? "NO" : "YES") << "\n";
    }
    return 0;
}