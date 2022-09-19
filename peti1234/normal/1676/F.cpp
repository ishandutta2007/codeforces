#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, k;
map<int, int> db, ert;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            db[x]++;
        }
        int maxi=0;
        for (auto p:db) {
            int id=p.first, cnt=p.second;
            if (cnt>=k) {
                ert[id]=ert[id-1]+1;
                if (ert[id]>ert[maxi]) maxi=id;
            }
        }
        if (!maxi) cout << -1 << "\n";
        else cout << maxi-ert[maxi]+1 << " " << maxi << "\n";
        db.clear(), ert.clear();
    }
    return 0;
}