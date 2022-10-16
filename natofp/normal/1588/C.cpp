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

const int nax = 3e5 + 5;
const int LOG = 20;
int a[nax];
int n;
ll pref[nax][2];

ll askpar(int lo, int hi){
    if(lo > hi) return 0LL;
    return pref[hi][0] - pref[lo - 1][0];
}

ll askniepar(int lo, int hi){
    if(lo > hi) return 0LL;
    return pref[hi][1] - pref[lo - 1][1];
}

ll mindod[nax][LOG];
ll maxuj[nax][LOG];

ll maxgo[nax];

vector<int> positions[nax];

ll howMany(int id, int seq){
    assert(positions[id].size() > 0);
    // jak duzy prefix do odjebania
    if(positions[id][0] <= seq) return (int)positions[id].size() - 1;
    int lo = 0;
    int hi = positions[id].size() - 1;
    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(positions[id][mid] > seq) lo = mid;
        else hi = mid;
    }
    int ans = lo;
    if(positions[id][hi] > seq) ans = hi;
    return (int)positions[id].size() - (ans + 2);
}

set<ll> present;
map<ll, int> renum;

ll ac1, ac2;

void brute(){
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int bal = 0;
            bool ac = true;
            for(int k=i;k<=j;k++){
                if(a[k] < bal) ac = false;
                bal = a[k] - bal;
            }
            if(bal != 0) ac = false;
            //if(ac) cout << i << " " << j << endl;
            ans += ac;
        }
    }
    //cout << ans << "\n";
    ac2 = ans;
    //cout << ac1 << " " << ac2 << endl;
}


void solve(){
    present.clear();
    renum.clear();
    cin >> n;
    for(int i=0;i<=n+1;i++) positions[i].clear();
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            pref[i][j] = pref[i - 1][j];
            pref[i][j] += (i % 2 == j) * a[i];
        }
    }
    for(int i=1;i<=n;i++){
        mindod[i][0] = a[i];
        maxuj[i][0] = -1e18;
        if(i < n){
            mindod[i][1] = a[i]; // mniejsze od zero to zle
            maxuj[i][1] = a[i] - a[i + 1]; // wieksze od zero to zle
        }
    }
    for(int j=2;j<LOG;j++){
        for(int i=1;i<=n;i++){
            if(i + (1 << j) - 1 > n) break;
            ll wasMinDod = mindod[i][j - 1];
            ll wasMaxUj = maxuj[i][j - 1];
            ll offset = askniepar(i, i + (1 << (j - 1)) - 1) - askpar(i, i + (1 << (j - 1)) - 1);
            if(i% 2 == 0) offset = -offset;
            ll jestMinDod = mindod[i + (1 << (j - 1))][j - 1] + offset;
            ll jestMaxUj = maxuj[i + (1 << (j - 1))][j - 1] + offset;
            mindod[i][j] = min(wasMinDod, jestMinDod);
            maxuj[i][j] = max(wasMaxUj, jestMaxUj);
        }
    }
    //cout << maxuj[1][2] << endl;


    for(int i=1;i<=n;i++){
        ll offset = 0;
        int canGo = 0;
        for(int j=LOG-1;j>=1;j--){
            if(i + canGo + (1 << j) - 1 > n) continue;
            ll maxUj = maxuj[i + canGo][j];
            ll minDod = mindod[i + canGo][j];
            if(maxUj + offset <= 0 && minDod + offset >= 0){
                i += canGo;
                canGo += (1 << j);
                ll bal = askpar(i, i + (1 << j) - 1) - askniepar(i, i + (1 << j) - 1);
                if(i % 2 == 1) bal = -bal;
                offset += bal;
                i -= (canGo - (1 << j));
            }
        }
        // maybe one more?
        offset = 0;
        int pos = i + canGo - 1;
        offset = askpar(i, pos) - askniepar(i, pos);
        if(i % 2 == 0) offset = -offset;
        while(pos < n && a[pos + 1] >= offset){
            offset = a[pos + 1] - offset;
            pos += 1;
        }
        maxgo[i] = pos;
        //return;
    }
    present.insert(0);
    renum[0] = 0;
    positions[0].pb(n + 1);
    int are = 1;
    ll ans = 0;
    for(int i=n;i>=1;i--){
        ll cur = askpar(i, n) - askniepar(i, n);
        if(present.count(cur) == 0){
            present.insert(cur);
            renum[cur] = are++;
        }
        positions[renum[cur]].pb(i);
        int canGo = maxgo[i];
        assert(canGo >= i);
        int teraz = howMany(renum[cur], canGo + 1);
        //if(i == 1) cout << "CO" << canGo << endl;
        //cout << "WA" << i << " " << teraz << endl;
        ans += howMany(renum[cur], canGo + 1);
    }
    cout << ans << "\n";
    //ac1 = ans;
    //brute();
}

void gene(){
    n = rand()%25 + 1;
    for(int i=1;i<=n;i++){
        a[i] = rand()%6+1;
    }
    solve();
    if(ac1 != ac2){
        cout << n << endl;
        for(int i=1;i<=n;i++) cout << a[i] << endl;
        cout << ac1 << " " << ac2 << endl;
        exit(0);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //solve();
    //return 0;
    //for(int i=0;i<100000;i++) gene();
    //return 0;
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}