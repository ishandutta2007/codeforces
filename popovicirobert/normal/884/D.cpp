#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

multiset <ll> mst;


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        mst.insert(x);
    }
    ll ans = 0;
    while(mst.size() > 1) {
        ll x = 0;
        x += *mst.begin();
        mst.erase(mst.begin());
        x += *mst.begin();
        mst.erase(mst.begin());
        if(mst.size() % 2 == 1) {
            x += *mst.begin();
            mst.erase(mst.begin());
        }
        mst.insert(x);
        ans += x;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}