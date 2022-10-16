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


void solve(){
    int n, k; cin >> n >> k;

    if(n == 4 && k == 3){
        cout << -1 << "\n";
        return;
    }
    vector<pii> ans;
    int ful = n - 1;
    if(k == n - 1){
        ans.pb(mp(0, 2));
        ans.pb(mp(1, n - 3));
        ans.pb(mp(n - 2, n - 1));
        for(int i=3;i<n/2;i++) ans.pb(mp(i, n - 1 - i));
    }
    else if(k == 0){
        for(int i=0;i<n/2;i++) ans.pb(mp(i,ful^i));
    }
    else{
        ans.pb(mp(k, n - 1));
        ans.pb(mp(0, ful ^ k));
        for(int i=0;i<n/2;i++){
            if(i != 0 && i != k && i != (ful ^ k)){
                ans.pb(mp(i, ful ^ i));
            }
        }
    }
    for(pii cur : ans) cout << cur.st << " " << cur.nd << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}