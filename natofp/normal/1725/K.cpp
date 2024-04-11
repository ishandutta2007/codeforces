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
pii dp[nax][3]; // l, r, x(?)
pii dp0[nax]; // a[i] -> ktory, l czy r

int a[nax];
int n, q;

int zap[nax][3];

const int LOG = 20;
pii jump[LOG][nax][3];
pii koniec = mp(0, 0);

int ans[nax];

pii last[nax];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    multiset<tuple<int, int, int> > alive;
    for(int i=1;i<=n;i++) alive.insert(mt(a[i], 0, i));
    cin >> q;
    for(int i=1;i<=q;i++){
        int tp; cin >> tp;
        if(tp == 1){
            int k, w; cin >> k >> w;
            alive.insert(mt(w, i, k));
            zap[i][0] = tp;
            zap[i][1] = k;
            zap[i][2] = w;
        }
        else if(tp == 2){
            int k; cin >> k;
            zap[i][0] = tp;
            zap[i][1] = k;
        }
        else{
            int l, r; cin >> l >> r;
            zap[i][0] = tp;
            zap[i][1] = l;
            zap[i][2] = r;
            while(alive.size()){
                auto it = (alive.lower_bound(mt(l, -1e9, -1e9)));
                if(it == alive.end()) break;
                auto [value, czas, pos] = (*it);
                if(l <= value && value <= r){
                    alive.erase(alive.find(*it));
                    int mid = (l + r) / 2;
                    // <= mid go to l
                    int togo = 0;
                    if(value > mid) togo = 1;
                    if(czas == 0){
                        dp0[pos] = mp(i, togo);
                    }
                    else{
                        if(zap[czas][0] == 1){
                            dp[czas][2] = mp(i, togo);
                        }
                        else{
                            int gg = 0;
                            if(value == zap[czas][2] + 1) gg = 1;
                            dp[czas][gg] = mp(i, togo);
                        }
                    }

                }
                else break;
            }
            alive.insert(mt(l - 1, i, -1));
            alive.insert(mt(r + 1, i, -1));
        }
    }

    for(int i=1;i<=q;i++){
        for(int j=0;j<3;j++){
            jump[0][i][j] = dp[i][j];
        }
    }

    for(int lv=1;lv<LOG;lv++){
        for(int i=1;i<=q;i++){
            for(int j=0;j<3;j++){
                pii skok = jump[lv - 1][i][j];
                if(skok == koniec) jump[lv][i][j] = koniec;
                else jump[lv][i][j] = jump[lv - 1][skok.st][skok.nd];
            }
        }
    }
    for(int i=1;i<=n;i++) last[i] = mp(a[i], 0);
    for(int i=1;i<=q;i++){
       // bool dbg = (i == 7);
        if(zap[i][0] == 1){
            last[zap[i][1]] = mp(zap[i][2], i);
        }

        if(zap[i][0] == 2){
            int ktory = zap[i][1];
            pii update = last[ktory];
            //if(dbg) cout << "A" << update.st << " " << update.nd << endl;
            //cout << "A" << i << " " << update.st << " " << update.nd << " " << ktory << "\n";
            pii gdzieJestem = mp(0, 0);
            if(update.nd == 0){
                pii skok = dp0[ktory];
                if(skok == koniec || skok.st > i){
                    cout << update.st << "\n";
                    continue;
                }
                else{
                    gdzieJestem = skok;
                }
            }
            else{
                gdzieJestem = mp(update.nd, 2);
            }
            //if(dbg) cout << "B" << gdzieJestem.st << " " << gdzieJestem.nd << endl;
            //cout << "B" << i << " " << gdzieJestem.st << " " << gdzieJestem.nd << endl;
            for(int j=LOG-1;j>=0;j--){
                pii skok = jump[j][gdzieJestem.st][gdzieJestem.nd];
                if(skok == koniec) continue;
                if(skok.st <= i){
                    gdzieJestem = skok;
                }
            }
            //if(dbg) cout << "C" << gdzieJestem.st << " " << gdzieJestem.nd << endl;
            //cout << "C" << i << " " << gdzieJestem.st << " " << gdzieJestem.nd << endl;
            if(gdzieJestem.nd == 2){
                cout << update.st << "\n";
            }
            else{
                int bonus = 1;
                if(gdzieJestem.nd == 0) bonus = -1;
                cout << zap[gdzieJestem.st][gdzieJestem.nd + 1] + bonus << "\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}