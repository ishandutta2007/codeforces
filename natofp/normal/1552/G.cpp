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

const int nax = 55;
vector<int> sorcik[nax];
int n, k;

vector<ll> possible; // bitmask, bitmask of set
ll done = 0;

vector<ll> nxt;

void faza(int f){
    ll curMask = 0;
    for(int x : sorcik[f]) curMask ^= (1LL << x);
    int len = sorcik[f].size();
    vector<ll> prefixMask; // 00111
    ll sum = 0;
    ll tmp = curMask;
    for(int i=0;i<=len;i++){
        prefixMask.pb(sum);
        ll lo = tmp - (tmp & (tmp - 1));
        tmp -= lo;
        sum += lo;
    }
    ll ksor = (((1LL << n) - 1) ^ curMask);
    ll activeSubmask = (curMask & done);
    int undetermined = __builtin_popcountll(curMask) - __builtin_popcountll(activeSubmask);
    for(ll cur : possible){
        ll value = (activeSubmask & cur);
        int ones = __builtin_popcountll(value);
        int zeros = __builtin_popcountll(activeSubmask) - ones;
        int Z = zeros;
        for(int cntZeros = 0; cntZeros <= undetermined; cntZeros++){
            ll maskValue = ((curMask ^ prefixMask[Z + cntZeros]) & curMask);
            ll go = cur;
            go &= ksor;
            go |= maskValue;
            nxt.pb(go);
        }
    }
    //sort(nxt.begin(), nxt.end());
    //nxt.erase(unique(nxt.begin(), nxt.end() ), nxt.end());
    possible = nxt;
    nxt.clear();
    done |= curMask;
}

void solve(){
    cin >> n >> k;
    if(n == 1){
        cout << "ACCEPTED" << "\n";
        return;
    }
    for(int i=1;i<=k;i++){
        int cnt; cin >> cnt;
        while(cnt--){
            int x; cin >> x;
            x--;
            sorcik[i].pb(x);
        }
    }
    possible.pb(0);
    for(int i=1;i<=k;i++) faza(i);
    ll fullMask = (1LL << n) - 1;
    bool bad = false;
    if(done != fullMask) bad = true;
    for(ll cur : possible){
        ll akt = (cur ^ fullMask) + 1;
        akt &= (akt - 1);
        if(akt) bad = true;
    }
    if(bad) cout << "REJECTED" << "\n";
    else cout << "ACCEPTED" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}