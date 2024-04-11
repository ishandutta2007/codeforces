#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
#define mt make_tuple

using namespace std;

const int nax = 2e5 + 5;
int a[nax];
vector<int> b;
int n, m;
set<int> u;
vector<int> occ[nax];
vector<int> r[nax];
vector<int> l[nax];
int mxEnd[nax];
int mnStart[nax];
int pop[nax];

const int roz = (1 << 20);

int tree[roz];

void upd(int lo, int hi, int u, int a, int b, int v){
    if(lo == a && b == hi){
        tree[u] = max(tree[u], v);
        return;
    }
    if(b <= a) return;
    int mid = (lo + hi) / 2;
    upd(lo, mid, u * 2, a, min(b, mid), v);
    upd(mid, hi, u * 2 + 1, max(a, mid), b, v);
}

int ask(int pos){
    pos += roz / 2;
    int ans = tree[pos];
    while(pos >= 1){
        ans = max(ans, tree[pos]);
        pos /= 2;
    }
    return ans;
}

const int INF = 2e9;

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    b.clear(); u.clear();
    for(int i=1;i<=n;i++) u.insert(a[i]);
    for(int x : u) b.pb(x);
    for(int i=1;i<=n;i++){
        a[i] = (int)(lower_bound(b.begin(), b.end(), a[i]) - b.begin());
    }
    int mx = u.size();
    for(int i=0;i<mx;i++){
        occ[i].clear();
    }
    for(int i=1;i<=n;i++) occ[a[i]].pb(i);
    for(int i=1;i<=n;i++) r[i].clear();
    for(int i=1;i<=n;i++) l[i].clear();
    for(int i=1;i<=m;i++){
        int x, y; cin >> x >> y;
        r[x].pb(y);
        l[y].pb(x);
    }
    mxEnd[0] = 0;
    for(int i=1;i<=n;i++){
        mxEnd[i] = mxEnd[i - 1];
        for(int x : r[i]) mxEnd[i] = max(mxEnd[i], x);
    }
    mnStart[n + 1] = n + 1;
    for(int i=n;i>=1;i--){
        mnStart[i] = mnStart[i + 1];
        for(int x : l[i]) mnStart[i] = min(mnStart[i], x);
    }

    for(int i=0;i<mx;i++){
        for(int j=0;j<occ[i].size();j++){
            int pos = occ[i][j];
            int lo = j;
            int hi = (int)occ[i].size() - 1;
            int most;
            if(mxEnd[pos] >= occ[i][hi]) most = hi;
            else{
                while(lo + 1 < hi){
                    int mid = (lo + hi) / 2;
                    if(mxEnd[pos] >= occ[i][mid]) lo = mid;
                    else hi = mid;
                }
                most = lo;
                if(mxEnd[pos] >= occ[i][hi]) most = hi;
            }
            int f1 = occ[i][j];
            int f2 = occ[i][most];
            if(f1 != f2){
                int fm = occ[i][most - 1];
                int fff = occ[i][j + 1];

                upd(0, roz / 2, 1, 1, f1 + 1, fm);
                upd(0, roz / 2, 1, f1 + 1, fff + 1, f2);
                upd(0, roz / 2, 1, fff + 1, n + 1, INF);

            }
        }
    }
    //cout << "A" << endl;
    int ans = n;
    for(int i=1;i<=n;i++){
        int xd = ask(i);
        ans = min(ans, max(0, xd - i + 1));
    }
    //cout << "B" <<
    cout << ans << "\n";
    for(int i=1;i<=n;i++){
        int w = i + roz / 2;
        while(w >= 1){
            tree[w] = -INF;
            w /= 2;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}