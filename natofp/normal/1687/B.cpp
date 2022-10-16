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

int que(vector<int> a){
    cout << "? ";
    for(int x : a) cout << x;
    cout << endl;
    fflush(stdout);
    int res; cin >> res;
    return res;
}

const int nax = 505;
int w[nax];

void solve(){
    int n, m; cin >> n >> m;
    for(int i=1;i<=m;i++){
        vector<int> cur;
        for(int j=1;j<i;j++) cur.pb(0);
        cur.pb(1);
        for(int j=i+1;j<=m;j++) cur.pb(0);
        w[i] = que(cur);
    }

    vector<pii> xd;
    for(int i=1;i<=m;i++) xd.pb(mp(w[i], i-1));
    sort(xd.begin(), xd.end());
    int cost = xd[0].st;
    vector<int> mask;
    for(int i=0;i<m;i++) mask.pb(0);
    mask[xd[0].nd] = 1;
    for(int i=1;i<(int)xd.size();i++){
        int kto = xd[i].nd;
        int wei = xd[i].st;

        mask[kto] = 1;
        int dif = que(mask) - cost;
        if(dif == wei){
            cost += wei;
        }
        else{
            mask[kto] = 0;
        }
    }
    cout << "! " << cost << endl;
    fflush(stdout);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}