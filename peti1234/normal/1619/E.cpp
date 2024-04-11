#include <bits/stdc++.h>

using namespace std;
int w;
int n, db[200005];
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            db[x]++;
        }
        bool baj=0;
        long long ans=0;
        for (int i=0; i<=n; i++) {
            for (int j=0; j<db[i]; j++) {
                sz.push_back(i);
            }
            if (baj) cout << -1 << " ";
            else cout << ans+db[i] << " ";
            if (sz.size()>0) {
                ans+=i-sz.back();
                db[sz.back()]--;
                sz.pop_back();
            } else {
                baj=1;
            }
        }
        cout << "\n";

        sz.clear();
        for (int i=0; i<=n; i++) {
            db[i]=0;
        }
    }
    return 0;
}
/*
1
3
0 1 3
*/