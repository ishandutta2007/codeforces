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
const int SQRT = 666;
int n, m;
map<int, vector<int> > banned;
map<int, int> cnt;
int a[nax];
vector<pii> occ[nax];
bool notAllowed[nax];
vector<int> rem;

int g(int x){
    return (int)(lower_bound(rem.begin(), rem.end(), x) - rem.begin());
}

void solve(){
    banned.clear();
    cnt.clear();
    rem.clear();
    cin >> n >> m;
    set<int> UU;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]] += 1;
        UU.insert(a[i]);
    }
    for(int x : UU) rem.pb(x);
    for(pii cur : cnt){
        int kto = cur.st;
        int ile = cur.nd;
        occ[ile].pb(mp(g(kto), kto));
    }
    for(int i=1;i<=m;i++){
        int x, y; cin >> x >> y;
        banned[x].pb(g(y));
        banned[y].pb(g(x));
    }
    vector<int> bigs;
    ll ans = 0;
    set<int> exist;
    for(int i=1;i<=n;i++) exist.insert(a[i]);
    vector<int> uni;
    for(int i=1;i<=n;i++){
        if(occ[i].size() > 0){
            uni.pb(i);
            sort(occ[i].begin(), occ[i].end());
            reverse(occ[i].begin(), occ[i].end());
            if(i > SQRT) bigs.pb(i);
        }
    }

    for(int x : exist){
        ll ile = cnt[x];
        vector<int> cur = banned[x]; // male
        for(int y : cur) notAllowed[y] = true;
        notAllowed[g(x)] = true;

        for(int i=1;i<=SQRT;i++){
            for(int j=0;j<occ[i].size();j++){
                pii cur = occ[i][j];
                if(notAllowed[cur.st]) continue;
                ans = max(ans, ((ll)x + cur.nd) * (ile + i));
                break;
            }
        }

        for(int y : bigs){
            for(int j=0;j<occ[y].size();j++){
                pii cur = occ[y][j];
                if(notAllowed[cur.st]) continue;
                ans = max(ans, ((ll)x + cur.nd) * (ile + y));
            }
        }

        for(int y : cur) notAllowed[y] = false;
        notAllowed[g(x)] = false;
    }
    for(int i=1;i<=n;i++) occ[i].clear();
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}