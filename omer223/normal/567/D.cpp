#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <intrin.h>
#include <deque>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

int howManyShips(int len, int a) {
    return (len + 1) / (a + 1);
}

int main() {
    fast;
    int n, k, a, m;
    cin >> n >> k >> a >> m;
    ll cnt = (n + 1) / (a + 1); //how many ships i can fit in
    int ans = -1;
    set<pii> s1;
    s1.insert({ n - 1,0 });
    //n==8
    //pos==4
    //[0,7], {7,0}, {4,-1e9}
    foru(i, 0, m) {
        int pos;
        cin >> pos; pos--;
        //get interval of pos
        auto it = s1.lower_bound({ pos,-1e9 });
        pii ii = *it;
        int l = ii.second, r = ii.first;
        //remove interval of pos 
        s1.erase(it);
        cnt -= howManyShips(r - l + 1, a);
        //insert split intervals
        //[l, r] pos -> [l, pos-1], [pos+1, r]
        if (l <= pos - 1)
            s1.insert({ pos - 1,l }), cnt += howManyShips(pos - 1 - l + 1, a);
        if (pos + 1 <= r)
            s1.insert({ r,pos + 1 }), cnt += howManyShips(r - (pos + 1) + 1, a);
        //check if cnt < k
        if (cnt < k) {
            if (ans == -1)ans = i + 1;
            else continue;
        }
    }
    cout << ans << '\n';
    return 0;
}