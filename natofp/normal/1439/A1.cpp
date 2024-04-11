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

const int nax = 105;
int a[nax][nax];

struct ope{
    int x[3];
    int y[3];
};

vector<ope> ans;

void goralewo(int x, int y){
    ope eh;
    vector<pii> all;
    all.pb(mp(x, y));
    all.pb(mp(x + 1, y));
    all.pb(mp(x + 1, y + 1));
    all.pb(mp(x, y + 1));
    for(int i=0;i<4;i++){
        pii skip = all[i];
        if(skip == mp(x, y)) continue;
        ope akt;
        int c = 0;
        for(int j=0;j<4;j++){
            if(i == j) continue;
            akt.x[c] = all[j].st;
            akt.y[c] = all[j].nd;
            c += 1;
        }

        ans.pb(akt);
    }
}

void goraprawo(int x, int y){
    ope eh;
    vector<pii> all;
    all.pb(mp(x, y));
    all.pb(mp(x + 1, y));
    all.pb(mp(x + 1, y - 1));
    all.pb(mp(x, y - 1));
    for(int i=0;i<4;i++){
        pii skip = all[i];
        if(skip == mp(x, y)) continue;
        ope akt;
        int c = 0;
        for(int j=0;j<4;j++){
            if(i == j) continue;
            akt.x[c] = all[j].st;
            akt.y[c] = all[j].nd;
            c += 1;
        }
        ans.pb(akt);
    }
}

void dollewo(int x, int y){
    ope eh;
    vector<pii> all;
    all.pb(mp(x, y));
    all.pb(mp(x - 1, y));
    all.pb(mp(x - 1, y + 1));
    all.pb(mp(x, y + 1));
    for(int i=0;i<4;i++){
        pii skip = all[i];
        if(skip == mp(x, y)) continue;
        ope akt;
        int c = 0;
        for(int j=0;j<4;j++){
            if(i == j) continue;
            akt.x[c] = all[j].st;
            akt.y[c] = all[j].nd;
            c += 1;
        }
        ans.pb(akt);
    }
}

void dolprawo(int x, int y){
    ope eh;
    vector<pii> all;
    all.pb(mp(x, y));
    all.pb(mp(x - 1, y));
    all.pb(mp(x - 1, y - 1));
    all.pb(mp(x, y - 1));
    for(int i=0;i<4;i++){
        pii skip = all[i];
        if(skip == mp(x, y)) continue;
        ope akt;
        int c = 0;
        for(int j=0;j<4;j++){
            if(i == j) continue;
            akt.x[c] = all[j].st;
            akt.y[c] = all[j].nd;
            c += 1;
        }
        ans.pb(akt);
    }
}

void solve(){
    ans.clear();
    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char s; cin >> s;
            a[i][j] = s - '0';
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == 1){
                if(i == 1){
                    if(j == 1) goralewo(i, j);
                    else goraprawo(i, j);
                }
                else{
                    if(j == 1) dollewo(i, j);
                    else dolprawo(i, j);
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto cur : ans){
        for(int i=0;i<3;i++){
            cout << cur.x[i] << " " << cur.y[i] << " ";
        }
        cout << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}