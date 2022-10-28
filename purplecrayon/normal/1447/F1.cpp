#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 31, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = MAXL*MAXN, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, a[MAXN], b[MAXN], _ps[2*MAXN];

int& ps(int c){ return _ps[c+MAXN]; }
void solve(){
    cin >> n;
    int cnt[101]={};
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
    int mx=*max_element(cnt, cnt+101);
    int pos=-1;
    for (int i = 1; i <= 100; i++) if (cnt[i] == mx){
        if (pos != -1){ cout << n; return; }
        pos = i;
    }
    int ans=0;
    for (int i = 1; i <= 100; i++) if (i != pos) {
        for (int j = 0; j < n; j++) {
            if (a[j] == pos) b[j]=1;
            else if (a[j] == i) b[j]=-1;
            else b[j]=0;
        }
        fill(_ps, _ps+2*MAXN, 1e9);
        ps(0)=-1; int c=0; int cans=0;
        for (int j = 0; j < n; j++){
            c += b[j];
            ans = max(ans, j-ps(c)); cans=max(cans, j-ps(c));
            ps(c) = min(ps(c), j);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}