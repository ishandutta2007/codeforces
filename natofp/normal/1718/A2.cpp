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

const int nax = 1e5 + 5;
int a[nax];
int pref[nax];
int n;
map<int, int> dp;
set<int> was;

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pref[i] = pref[i - 1] ^ a[i];
    }

    int ans = n;
    for(int i=1;i<=n;i++){
        if(a[i] == 0){
            ans--;
            continue;
        }
        int j = i;
        while(j + 1 <= n && a[j + 1] != 0) j++;
        dp.clear();
        was.clear();
        int best = 0;
        for(int k=i-1;k<=j;k++){
            int cur = pref[k];
            if(was.count(cur)) dp[cur]++;
            dp[cur] = max(dp[cur], best);
            best = max(best, dp[cur]);
            was.insert(cur);
        }
        ans -= best;
        i = j;
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