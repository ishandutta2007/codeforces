#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int tq=0;
const int hx1 = 11, hy1 = 417, hx2 = 11, hy2 = 418;

bool qry(int x1, int x2, int y1, int y2){
    tq++;
    // bool c=0; x1++, y1++, x2++, y2++;
    // c = c^(x1 <= hx1 && hx1 <= x2 && y1 <= hy1 && hy1 <= y2);
    // c = c^(x1 <= hx2 && hx2 <= x2 && y1 <= hy2 && hy2 <= y2);
    // return c;
    cout << "? " << (x1+1) << ' ' << (y1+1) << ' ' << (x2+1) << ' ' << (y2+1) << '\n'; cout.flush();
    int x; cin >> x; while (x < 0);
    return bool(x&1);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<pair<int, int>> ans;

void one(){
    vector<int> v(n); iota(v.begin(), v.end(), 0); shuffle(v.begin(), v.end(), rng);
    for (auto i : v) if (sz(ans) < 2) if (qry(i, i, 0, n-1)) {
        int lo=-1, hi=n, mid=(lo+hi)/2;
        while (lo < mid && mid < hi){
            if (qry(i, i, 0, mid)) hi=mid;
            else lo=mid;
            mid=(lo+hi)/2;
        }
        ans.emplace_back(i, hi);
    }
}
void two(){
    vector<int> v(n); iota(v.begin(), v.end(), 0); shuffle(v.begin(), v.end(), rng);
    for (auto i : v) if (sz(ans) < 2) if (qry(0, n-1, i, i)) {
        int lo=-1, hi=n, mid=(lo+hi)/2;
        while (lo < mid && mid < hi){
            if (qry(0, mid, i, i)) hi=mid;
            else lo=mid;
            mid=(lo+hi)/2;
        }
        //cerr << i << '\n';
        ans.emplace_back(hi, i);
    }
}
void solve(){
    cin >> n;
    
    if (rand()%2) one(), two();
    else two(), one();
    
    assert(sz(ans) == 2);
    cout << "! ";
    for (auto it : ans) cout << (it.first+1) << ' ' << (it.second+1) << ' '; cout << '\n'; cout.flush();
    cerr << tq << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}