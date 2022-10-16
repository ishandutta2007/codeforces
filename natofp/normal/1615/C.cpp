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

string s[2];
int cnt[2][2];

void solve(){
    int n; cin >> n;
    cin >> s[0] >> s[1];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++) cnt[i][j] = 0;
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cnt[i][s[i][j] - '0'] += 1;
        }
    }
    if(cnt[0][1] != cnt[1][1] && cnt[0][1] != n - cnt[1][1] + 1){
        cout << -1 << "\n";
        return;
    }
    int ans = 1e9;
    if(cnt[0][1] == cnt[1][1]){
        int m = 0;
        for(int i=0;i<n;i++) m += (s[0][i] != s[1][i]);
        ans = min(ans, m);
    }
    if(cnt[0][1] == n + 1 - cnt[1][1]){
        int m = 0;
        for(int i=0;i<n;i++){
            m += (s[0][i] == s[1][i]);
        }
        int w = 1e9;
        for(int i=0;i<n;i++){
            if(s[1][i] == '1'){
                int cur = m;
                if(s[1][i] == s[0][i]) cur -= 1;
                else cur += 1;
                w = min(w, cur);
            }
        }
        w += 1;
        ans = min(ans, w);
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