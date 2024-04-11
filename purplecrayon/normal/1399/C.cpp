#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 50;

int w[MAXN];

void solve(){
    int n; cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) cin >> w[i], cnt[w[i]]++;
    int ans = 0;
    for (int wi = 0; wi <= 2*n; wi++){
        int cans = 0;
        for (auto it : cnt){
            // cout << it.first << " " << it.second << endl;
            if (wi-it.first > it.first){
                cans += min(it.second, cnt[wi-it.first]);
            }
        }
        if ((wi&1) == 0) cans += cnt[wi/2]/2;
        ans = max(ans, cans);
    }
    cout << ans << "\n";
}

int main(){
    int t; cin >> t;
    while (t--) solve();
}