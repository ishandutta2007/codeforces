#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)(1<<18);
int cnt[N];

int main(){
    int h;
    cin >> h;
    int n = (1 << h) - 1;
    int u, v, w;
    int id;
    bool eq;
    for(int chk = 0 ; chk < 420; chk ++ ){
        while(1){
            u = ((int)rng() % n + n) % n + 1;
            v = ((int)rng() % n + n) % n + 1;
            w = ((int)rng() % n + n) % n + 1;
            if(u == v || v == w || u == w) eq = true;
            else eq = false;
            if(eq == false)break;
        }
        cout << "? " << u << " " << v << " " << w << "\n";
        fflush(stdout);
        cin >> id;
        cnt[id] ++ ;
    }
    vector<pii> ord;
    for(int i = 1; i <= n; i ++ ){
        ord.push_back(mp(cnt[i], i));
    }
    sort(ord.begin(), ord.end());
    reverse(ord.begin(), ord.end());
    int i1 = ord[0].se;
    int i2 = ord[1].se;
    int res = -1;
    for(int i = 1; i <= n; i ++ ){
        if(i == i1 || i == i2) continue;
        cout << "? " << i << " " << i1 << " " << i2 << "\n";
        fflush(stdout);
        cin >> id;
        if(id == i){
            res = i;
        }
    }
    cout << "! " << res << "\n";
    fflush(stdout);
    return 0;
}