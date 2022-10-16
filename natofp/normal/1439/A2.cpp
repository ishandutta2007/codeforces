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

void app(ope cur){
    for(int i=0;i<3;i++){
        int xx = cur.x[i];
        int yy = cur.y[i];
        a[xx][yy] ^= 1;
    }
}

vector<int> gg(ope cur){
    vector<int> x;
    vector<pii> go;
    for(int i=0;i<3;i++){
        go.pb(mp(cur.x[i], cur.y[i]));
    }
    sort(go.begin(), go.end());
    for(pii cur : go){
        x.pb(cur.st);
        x.pb(cur.nd);
    }
    return x;
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

    for(int i=1;i<=n-2;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == 1){
                ope nowe;
                nowe.x[0] = i;
                nowe.y[0] = j;
                nowe.x[1] = i + 1;
                nowe.y[1] = j;
                nowe.x[2] = i + 1;
                if(j == 1){
                    nowe.y[2] = j + 1;
                }
                else nowe.y[2] = j - 1;
                app(nowe);
                ans.pb(nowe);
            }
        }
    }
    for(int j=1;j<=m-2;j++){
        if(a[n - 1][j] == 0 && a[n][j] == 0) continue;
        if(a[n - 1][j] == 0 && a[n][j] == 1){
            ope nowe;
            nowe.x[0] = n;
            nowe.y[0] = j;
            nowe.x[1] = n - 1;
            nowe.y[1] = j + 1;
            nowe.x[2] = n;
            nowe.y[2] = j + 1;
            app(nowe);
            ans.pb(nowe);
        }
        if(a[n - 1][j] == 1 && a[n][j] == 0){
            ope nowe;
            nowe.x[0] = n - 1;
            nowe.y[0] = j;
            nowe.x[1] = n - 1;
            nowe.y[1] = j + 1;
            nowe.x[2] = n;
            nowe.y[2] = j + 1;
            app(nowe);
            ans.pb(nowe);
        }
        if(a[n - 1][j] == 1 && a[n][j] == 1){
            ope nowe;
            nowe.x[0] = n - 1;
            nowe.y[0] = j;
            nowe.x[1] = n;
            nowe.y[1] = j;
            nowe.x[2] = n;
            nowe.y[2] = j + 1;
            app(nowe);
            ans.pb(nowe);
        }
    }

    auto cp = ans;
    ans.clear();
    if(a[n - 1][m - 1] == 1){
        goralewo(n - 1, m - 1);
    }
    if(a[n][m - 1] == 1){
        dollewo(n, m - 1);
    }
    if(a[n - 1][m] == 1){
        goraprawo(n - 1,m );
    }
    if(a[n][m] == 1){
        dolprawo(n, m);
    }
    //sort(ans.begin(), ans.end());
    vector<ope> bonus;
    map<vector<int>, int > es;
    for(auto cur : ans){
        es[gg(cur)] += 1;
    }
    for(auto cur : es){
        if(cur.nd & 1){
            for(auto kto : ans){
                if(gg(kto) == cur.st){
                    bonus.pb(kto);
                    break;
                }
            }
        }
    }
    ans = cp;
    for(auto cur : bonus){
        app(cur);
    }
    for(auto cur : bonus) ans.pb(cur);

    assert(ans.size() <= n * m);
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