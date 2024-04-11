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

const int nax = 5e5 + 5;
int dp[nax];
bool ex[333];

void prep(){
    for(int i=2;i<nax;i++){
        int cnt = 0;
        for(int k=0;k<333;k++) ex[k] = false;
        for(int j=1;j<=i-1;j++){
            int w1 = (j - 1);
            int w2 = (i - 2 - w1);
            int xo = (dp[w1] ^ dp[w2]);
            ex[xo] = true;
            cnt++;
            if(cnt == 222) break;
        }
        int ptr = 0;
        while(ex[ptr]) ptr++;
        dp[i] = ptr;
    }
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> games;
    int red = 0;
    int blue = 0;
    for(char x : s){
        if(x == 'R') red++;
        else blue++;
    }
    for(int i=0;i<n;i++){
        if(i == n - 1) break;
        if(s[i + 1] == s[i]) continue;
        int j = i;
        while(j + 1 < n && s[j + 1] != s[j]) j++;
        games.pb(j - i + 1);
        i = j;
    }
    int wyn = 0;
    for(int x : games) wyn ^= dp[x];
    if(wyn) red++;
    if(red > blue) cout << "Alice" << "\n";
    else cout << "Bob" << "\n";


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    prep();
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}