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
 
int n, m;
const int nax = 4e5 + 10;
ll dp[2][nax];
int przed[nax];
int minsuf[nax];
 
vector<pii> inters;
vector<int> pkty;
vector<int> poczatki;
 
int id(int value){
    if(value >= poczatki.back()) return -1; // TODO
    return (int)(upper_bound(poczatki.begin(), poczatki.end(), value) - poczatki.begin());
}
 
void solve(){
    set<int> pts;
    set<pii> intervals;
    cin >> n >> m;
    for(int i=0;i<=n*2+7;i++){
        for(int j=0;j<2;j++) dp[j][i] = 4e9;
    }
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        pts.insert(x);
    }
    for(int i=1;i<=m;i++){
        int x, y; cin >> x >> y;
        intervals.insert(mp(x, y));
    }
 
    set<pii> done;
    for(pii cur : intervals){
        auto it = pts.lower_bound(cur.st);
        if(it != pts.end()){
            int v = (*it);
            if(v <= cur.nd) done.insert(cur);
        }
    }
    for(pii cur : done){
        intervals.erase(cur);
    }
 
    set<int> usefulPTS;
    for(pii cur : intervals){
        auto it = pts.lower_bound(cur.st);
        if(it != pts.begin()){
            it--;
            usefulPTS.insert(*it);
        }
        it = pts.lower_bound(cur.st);
        if(it != pts.end()){
            usefulPTS.insert(*it);
        }
    }
    pts = usefulPTS;
    if(intervals.size() == 0){
        cout << 0 << "\n";
        return;
    }
    inters.clear();
    pkty.clear();
    for(pii cur : intervals) inters.pb(cur);
    for(int x : pts) pkty.pb(x);
    int v = (*pts.begin());
    int ac = 0;
    for(pii cur : inters){
        if(cur.nd < v) ac++;
    }
    przed[0] = ac;
    n = pkty.size();
    m = inters.size();
    for(int i=1;i<pts.size();i++){
        int bef = przed[i - 1] - 1;
        int v = pkty[i];
        while(bef < m - 1 && inters[bef + 1].nd < v) bef++;
        przed[i] = bef + 1;
    }
    poczatki.clear();
    for(pii cur : inters){
        poczatki.pb(cur.st);
    }
 
    ll mini = 4e9;
    if(przed[0] == 0){
        dp[0][0] = dp[1][0] = 0;
    }
    else{
        for(pii cur : inters){
            if(cur.nd < pkty[0]) mini = min(mini, (ll)cur.nd);
        }
        ll go = pkty[0] - mini;
        dp[0][0] = go;
        dp[1][0] = go * 2;
    }
    minsuf[m - 1] = inters[m - 1].nd;
    for(int i=m-2;i>=0;i--){
        minsuf[i] = min(minsuf[i + 1], inters[i].nd);
    }
 
    int wsk = 0;
    while(wsk < m && inters[wsk].nd < pkty[0]) wsk++;
    for(int i=1;i<n;i++){
        set<int> active;
        set<pii> itr;
        while(wsk < m && inters[wsk].nd < pkty[i]){
            active.insert(inters[wsk].nd);
            itr.insert(inters[wsk]);
            wsk++;
        }
        if(active.empty()){
            dp[0][i] = dp[1][i] = dp[0][i - 1];
        }
        else{
            for(pii cur : itr){
                ll cost = cur.st - pkty[i - 1];
                ll ent = 0;
                int to = id(cur.st);
                if(to != -1){
                    ll m = max(0LL, (ll)pkty[i] - minsuf[to]);
                    ent = m;
                }
                dp[0][i] = min(dp[0][i], dp[0][i - 1] + ent + cost * 2);
                dp[0][i] = min(dp[0][i], dp[1][i - 1] + ent + cost);
                dp[1][i] = min(dp[1][i], dp[0][i - 1] + ent * 2 + cost * 2);
                dp[1][i] = min(dp[1][i], dp[1][i - 1] + ent * 2 + cost);
            }
            // TODO
            dp[0][i] = min(dp[0][i], dp[0][i - 1] + pkty[i] - (*active.begin()));
            dp[1][i] = min(dp[1][i], dp[0][i - 1] + (pkty[i] - (*active.begin())) * 2);
        }
    }
 
    if(inters.back().st > pkty[n - 1]){
        ll d = inters.back().st - pkty[n - 1];
        ll ans = dp[0][n - 1] + d * 2;
        ans = min(ans, dp[1][n - 1] + d);
        cout << ans << "\n";
    }
    else{
        cout << dp[0][n - 1] << "\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
 
    return 0;
}