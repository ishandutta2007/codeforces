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
const int nax = 1e5 + 5;
string s;
ll n,a,b,c;
int cnt[2];
ll pref[nax];
ll all[2];

void solve(){
    cin >> n >> a >> b >> c;
    cin >> s;
    fill(cnt,cnt+2,0);
    for(int i=1;i<n;i++){
        if(s[i] == s[i - 1]){
            cnt[s[i] - '0'] += 1;
        }
    }
    fill(all,all+2,0);
    for(int i=0;i<n;i++){
        all[s[i] - '0'] += 1;
    }
    vector<ll> przerwy;
    ll cur = -420420;
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            if(cur > 0) przerwy.pb(cur);
            cur = 0;
        }
        else cur += 1;
    }
    sort(przerwy.begin(), przerwy.end());
    if(przerwy.size()){
        pref[0] = przerwy[0];
        for(int i=1;i<przerwy.size();i++){
            pref[i] = pref[i - 1] + przerwy[i];
        }
    }
    ll ans = -1e18;
    for(int msk=0;msk<4;msk++){
        for(int cnt13=0;cnt13<=all[0];cnt13++){
            int fi = ((msk & 1) > 0);
            int la = ((msk & 2) > 0);
            int cnt2 = cnt13;
            if(fi == la){
                if(fi == 0) cnt2 -= 1;
                else cnt2 += 1;
            }
            if(cnt13 < 0 || cnt13 > all[0] || cnt2 < 0 || (cnt2 > all[1] - 1 && cnt2 > 0)) continue;
            int deletedGaps = 0;
            if(cnt2 > cnt[1]){
                deletedGaps = cnt2 - cnt[1];
            }
            if(deletedGaps > przerwy.size()) continue;
            int forcedBad = 0;
            forcedBad = deletedGaps;
            forcedBad = max(forcedBad, cnt13 - cnt[0]);

            bool good = true;
            if(deletedGaps > 0){
                int before = cnt13;
                if(la == 0) before -= 1;
                int needOpe = pref[deletedGaps - 1];
                if(needOpe > before) good = false;
            }
            if(good) ans = max(ans, c * forcedBad * -1 + b * cnt2 + a * (cnt13 - forcedBad));
        }
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