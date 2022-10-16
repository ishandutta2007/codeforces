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

using namespace std;

int n;
string s, t;

vector<int> pos[26];
int done[26];


struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve(){
    cin >> n;
    cin >> s >> t;
    string tmp = s;
    sort(tmp.begin(), tmp.end());
    if(tmp >= t){
        cout << -1 << "\n";
        return;
    }
    for(int i=0;i<26;i++) pos[i].clear();
    ll ans = 1e18;
    for(int i=0;i<n;i++){
        char cur = s[i];
        pos[cur - 'a'].pb(i);
    }
    fill(done, done + 26, 0);
    ll curCost = 0;

    FenwickTree tri(n + 3);

    for(int i=0;i<n;i++){
        int bound = (t[i] - 'a');
        for(int j=0;j<bound;j++){
            if(done[j] == pos[j].size()) continue;
            int wh = pos[j][done[j]];
            int toGo = (wh - tri.sum(0, wh - 1));
            ans = min(ans, curCost + toGo);
        }
        char need = t[i];
        int value = need - 'a';
        if(done[value] == pos[value].size()) break;
        int where = pos[value][done[value]];
        tri.add(where, 1);
        int taken = tri.sum(0, where - 1);
        int toGo = (where - taken);
        curCost += toGo;
        done[value] += 1;

    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}