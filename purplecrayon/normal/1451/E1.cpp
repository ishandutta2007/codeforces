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

int qA(int i, int j){
    cout << "AND " << (i+1) << ' ' << (j+1) << '\n'; cout.flush();
    int x; cin >> x; if (x == -1) exit(0);
    return x;
}
int qX(int i, int j){
    cout << "XOR " << (i+1) << ' ' << (j+1) << '\n'; cout.flush();
    int x; cin >> x; if (x == -1) exit(0);
    return x;
}
int qO(int i, int j){
    cout << "OR " << (i+1) << ' ' << (j+1) << '\n'; cout.flush();
    int x; cin >> x; if (x == -1) exit(0);
    return x;
}
void solve(){
    int n; cin >> n;
    int axb=qX(0, 1), bxc=qX(1, 2), axc=axb^bxc, aab=qA(0, 1), aac=qA(0, 2), bac=qA(1, 2);
    int apb = axb + 2*aab;
    int apc = axc + 2*aac;
    int bpc = bxc + 2*bac;
    int a = (apb+apc-bpc)/2;
    int b = apb-a;
    int c = apc-a;
    vector<int> ans(n);
    ans[0] = a, ans[1] = b, ans[2] = c;
    for (int i = 3; i < n; i++){
        int x = qX(0, i);
        ans[i] = a^x;
    }
    cout << "! ";
    for (auto it : ans) cout << it << ' '; cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}