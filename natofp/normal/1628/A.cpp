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

const int nax = 2e5 + 5;
int a[nax];
int cnt[nax];
int n;

void solve(){
    cin >> n;
    fill(cnt, cnt + n + 1, 0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    int lo = 1;
    vector<int> ans;
    while(lo <= n){
        int mx = 0;
        while(cnt[mx] > 0) mx += 1;
        set<int> met;
        while(1){
            int cur = a[lo++];
            cnt[cur] -= 1;
            if(cur <= mx) met.insert(cur);
            if(met.size() == mx) break;
        }
        ans.pb(mx);
    }
    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
    cout << "\n";


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}