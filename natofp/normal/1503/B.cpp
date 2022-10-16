#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

int red(){
    int x; cin >> x;
    return x;
}

void odp(int r, int c, int col){
    cout<<col<<" "<<r<<" "<<c<<endl;
    fflush(stdout);
}


void solve(){
    int n; cin >> n;
    vector<pii> p, np;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i + j) % 2 == 0) p.pb(mp(i, j));
            else np.pb(mp(i, j));
        }
    }
    while(np.size() && p.size()){
        int x = red();
        if(x == 1 || x == 3){
            // bierzemy p
            pii pole = p.back();
            p.pop_back();
            odp(pole.st, pole.nd, 2);
        }
        else if(x == 2){
            pii pole = np.back();
            np.pop_back();
            odp(pole.st, pole.nd, 1);
        }
    }
    set<int> opcje;
    for(int i=1;i<=3;i++) opcje.insert(i);
    if(p.size() == 0) opcje.erase(2);
    else opcje.erase(1);

    int rest = np.size() + p.size();
    vector<pii> xd;
    if(p.size()) xd = p;
    else xd = np;

    while(rest--){
        int x = red();
        pii pole = xd.back();
        xd.pop_back();
        int col = 1;
        while(opcje.count(col) == 0 || x == col) col++;
        odp(pole.st, pole.nd, col);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}