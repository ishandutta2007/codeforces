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

struct segtreeMax{
    vector<int> tree;
    int roz;
    const int inf = 1e9;

    segtreeMax(){
        roz = 1;
        tree.clear();
    }

    void init(int n){
        while(roz <= n) roz *= 2;
        roz *= 2;
        tree.clear(); tree.resize(roz, -inf);
    }

    void update(int pos, int val){
        pos += roz / 2;
        tree[pos] = val;
        pos /= 2;
        while(pos >= 1){
            tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
            pos /= 2;
        }
    }

    int ask(int lo, int hi){
        if(lo > hi) return -inf;
        lo += roz / 2; hi += roz / 2;
        int res = max(tree[lo], tree[hi]);
        while(lo / 2 != hi / 2){
            if((lo & 1) == 0) res = max(res, tree[lo ^ 1]);
            if(hi & 1) res = max(res, tree[hi ^ 1]);
            lo /= 2; hi /= 2;
        }
        return res;
    }
};

const int nax = 2e5 + 5;
int a[nax];
int n;
int ros[nax];
int mal[nax];
const int inf = 1e9;

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n <= 2){
        cout << n * (n + 1) / 2 << "\n";
        return;
    }
    ros[n] = mal[n] = n;
    for(int i=n-1;i>=1;i--){
        if(a[i] < a[i + 1]) ros[i] = ros[i + 1];
        else ros[i] = i;
        if(a[i] > a[i + 1]) mal[i] = mal[i + 1];
        else mal[i] = i;
    }
    ll ans = 3;
    segtreeMax RM, MR;
    RM.init(n + 5);
    MR.init(n + 5);
    RM.update(a[n], n);
    MR.update(a[n], n);
    int MRptr = n;
    int RMptr = n;
    for(int i=n-2;i>=1;i--){
        int rng = ros[i + 1];
        int bestMR = rng;
        while(RMptr > rng){
            RM.update(a[RMptr + 1], -inf);
            RMptr--;
        }
        bestMR = max(bestMR, RM.ask(0, a[i] - 1));
        rng = mal[i + 1];
        int bestRM = rng;
        while(MRptr > rng){
            MR.update(a[MRptr + 1], -inf);
            MRptr--;
        }
        bestRM = max(bestRM, MR.ask(a[i] + 1, n));
        MR.update(a[i + 1], bestMR);
        RM.update(a[i + 1], bestRM);
        int opt = max(bestMR, bestRM);
        if(a[i] > a[i + 1]) opt = max(opt, MR.ask(1, n));
        else opt = max(opt, RM.ask(1, n));
        ans += opt - i + 1;
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}