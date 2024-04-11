#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 150000;

struct Data {
    ll val, pos;
    bool operator <(const Data &other) const {
        if(val == other.val)
            return pos < other.pos;
        return val < other.val;
    }
};

multiset <Data> mst;
multiset <Data> :: iterator it, it1;

ll sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        mst.insert({x, i});
    }
    ll val = 0;
    while(1) {
        it1 = it = mst.lower_bound({val, 0});
        it1++;
        if(it1 == mst.end()) {
            break;
        }
        if(it1 -> val == it -> val) {
            ll nr = 2 * it -> val;
            int p = it1 -> pos;
            it1++;
            mst.erase(it, it1);
            mst.insert({nr, p});
        }
        else {
            val = it1 -> val;
        }
    }
    for(auto it : mst) {
        sol[it.pos] = it.val;
    }
    cout << mst.size() << "\n";
    for(i = 1; i <= n; i++) {
        if(sol[i] > 0)
            cout << sol[i] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}