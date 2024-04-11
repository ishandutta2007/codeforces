#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    vector <int> t(n + 1), b(n + 1);
    for(i = 1; i <= n; i++) {
        cin >> t[i] >> b[i];
    }

    vector <int> ord(n + 1);
    iota(ord.begin(), ord.end(), 0);

    sort(next(ord.begin()), ord.end(), [&](const int &x, const int &y) {

                return b[x] < b[y];

         });

    multiset <int> mst;
    ll s = 0, ans = 0;

    for(i = n; i >= 1; i--) {

        ans = max(ans, 1LL * (s + t[ord[i]]) * b[ord[i]]);

        mst.insert(t[ord[i]]);
        s += t[ord[i]];

        if(mst.size() > k - 1) {
            s -= *mst.begin();
            mst.erase(mst.begin());
        }
    }

    cout << ans;


    //cin.close();
    //cout.close();
    return 0;
}