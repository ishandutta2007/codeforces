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

vector<pii> ans;
multiset<int> state;
int n;

void app(int x, int y){
    state.erase(state.find(x));
    state.erase(state.find(y));
    state.insert(x + y);
    state.insert(abs(x - y));
    ans.pb(mp(x, y));
}

void reku(int n, int mul){
    if(n <= 2) return;
    if(n == 3){
        app(mul, mul * 3);
        return;
    }
    int big = 4;
    while(big * 2 <= n) big *= 2;
    int cnt = n - big;
    for(int i=1;i<=cnt;i++){
        app((big - i) * mul, (big + i) * mul);
    }
    reku(cnt, mul * 2);
    reku(big - cnt - 1, mul);
}

void solve(){
    cin >> n;
    if(n == 2){
        cout << -1 << "\n";
        return;
    }
    state.clear();
    ans.clear();
    for(int i=1;i<=n;i++) state.insert(i);
    reku(n, 1);
    int cur = 1;
    while(state.count(cur) <= 1) cur *= 2;
    app(cur, cur);
    int target = 1;
    while(target < n) target *= 2;
    assert(state.count(0) == 1);
    while(1){
        auto it = (state.begin());
        it++;
        int cur = (*it);
        if(cur == target) break;
        app(0, cur);
        app(cur, cur);
    }
    app(0, target);
    int small = (*state.begin());
    int big = (*state.rbegin());
    assert(small == big && small == target);
    assert(ans.size() <= n * 20);

    cout << ans.size() << "\n";
    for(pii cur : ans) cout << cur.st << " " << cur.nd << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();
    return 0;
}