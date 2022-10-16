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

const int nax = 1e4 + 5;
ll a[nax];
ll pref[nax];
ll suf[nax];
int n;

int perm[nax][nax];

void calcPerm(){
    perm[1][1] = 1;
    for(int i=2;i<=n;i++){
        int smoler = 0;
        for(int j=1;j<i;j++) smoler += (a[j] < a[i]);
        perm[i][smoler + 1] = i;
        for(int j=1;j<=i-1;j++){
            perm[i][j + (j > smoler)] = perm[i - 1][j];
        }
    }
}

ll calc(int lo, int hi){
    if(lo > hi) return 0LL;
    ll wsp = a[lo];
    for(int i=lo;i<=hi;i++) wsp = min(wsp, a[i]);
    ll ans = wsp * (hi - lo + 1);
    ll mini = wsp;
    int biggestBanned = 0;
    ll OptSec = 0;
    int ptr = 1;
    for(int i=hi+1;i<=n;i++){
        mini = min(mini, a[i]);
        ll bound = wsp - mini;
        while(ptr <= lo - 1){
            int id = perm[lo - 1][ptr];
            if(a[id] < bound){
                ll can = hi - (biggestBanned + 1) + 1;
                OptSec = max(OptSec, can * a[id]);
                ptr += 1;
                biggestBanned = max(biggestBanned, id);
            }
            else break;
        }
        OptSec = max(OptSec, (hi - biggestBanned) * bound);
        ans = max(ans, OptSec + mini * (i - lo + 1));
    }
    return ans;
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    pref[1] = a[1];
    for(int i=2;i<=n;i++){
        pref[i] = pref[i - 1];
        ll hei = a[i];
        for(int j=i;j>=1;j--){
            hei = min(hei, a[j]);
            pref[i] = max(pref[i], hei * (i - j + 1));
        }
    }
    suf[n] = a[n];
    for(int i=n-1;i>=1;i--){
        suf[i] = suf[i + 1];
        ll hei = a[i];
        for(int j=i;j<=n;j++){
            hei = min(hei, a[j]);
            suf[i] = max(suf[i], hei * (j - i + 1));
        }
    }
    ll ans = pref[n];
    for(int i=0;i<=n;i++) ans = max(ans, pref[i] + suf[i + 1]);

    vector<pii> spec;
    stack<int> pos;
    pos.push(1);
    for(int i=2;i<=n;i++){
        while(pos.size() && a[pos.top()] >= a[i]) pos.pop();
        if(pos.size()) spec.pb(mp(pos.top(), i));
        else spec.pb(mp(1, i));
        pos.push(i);
    }

    while(!pos.empty()) pos.pop();
    pos.push(n);
    for(int i=n-1;i>=1;i--){
        while(pos.size() && a[pos.top()] > a[i]) pos.pop();
        if(pos.size()) spec.pb(mp(i, pos.top()));
        else spec.pb(mp(i, n));
        pos.push(i);
    }

    for(pii cur : spec){
        int lo = cur.st + 1;
        int hi = cur.nd - 1;
        if(lo > hi) continue;
        ll mini = a[lo];
        for(int i=lo;i<=hi;i++) mini = min(mini, a[i]);
        ll origMini = mini;
        int p1 = lo;
        int p2 = hi;
        while(p1 > 1 || p2 < n){
            if(p1 == 1){
                p2++;
                mini = min(mini, a[p2]);
            }
            else if(p2 == n){
                p1--;
                mini = min(mini, a[p1]);
            }
            else{
                if(a[p1 - 1] <= a[p2 + 1]){
                    p2++;
                    mini = min(mini, a[p2]);
                }
                else{
                    p1--;
                    mini = min(mini, a[p1]);
                }
            }
            ll pos = mini * (p2 - p1 + 1) + (origMini - mini) * (hi - lo + 1);
            ans = max(ans, pos);
        }
    }

    calcPerm();
    for(pii cur : spec) ans = max(ans, calc(cur.st + 1, cur.nd - 1));
    reverse(a + 1, a + n + 1);
    calcPerm();
    for(pii cur : spec) ans = max(ans, calc(cur.st + 1, cur.nd - 1));

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}