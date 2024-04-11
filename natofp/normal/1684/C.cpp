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

int n, m;
vector<vector<int> > a, b;
const int nax = 2e5 + 5;

int lo[nax];
int hi[nax];

void solve(){
    a.clear(); b.clear();
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        vector<int> cur;
        for(int j=1;j<=m;j++){
            int x; cin >> x;
            cur.pb(x);
        }
        a.pb(cur);
        sort(cur.begin(), cur.end());
        b.pb(cur);
    }
    vector<int> bad;
    for(int j=0;j<m;j++){
        vector<pii> xd;
        for(int i=0;i<n;i++){
            int value = a[i][j];
            int pos1 = (int)(lower_bound(b[i].begin(), b[i].end(), value) - b[i].begin());
            int pos2 = (int)(lower_bound(b[i].begin(), b[i].end(), value + 1) - b[i].begin());
            pos2 -= 1;
            //if(j == 0) cout << "WA" << value << " " << pos1 << " " << pos2 << endl;
            xd.pb(mp(pos1, pos2));
        }
        int mi = 2e9;
        int ma = -2e9;
        for(pii cur : xd){
            mi = min(mi, cur.nd);
            ma = max(ma, cur.st);
        }
        if(mi < ma){
            cout << -1 << "\n";
            return;
        }
        lo[j] = ma;
        hi[j] = mi;
        if(j < lo[j] || j > hi[j]) bad.pb(j);
    }
    //cout << lo[0] << " " << hi[0] << " " << lo[1] << " " << hi[1] << endl;
   //return;
    if(bad.size() > 2){
        cout << -1 << "\n";
        return;
    }
    else if(bad.size() == 2){
        int j1 = bad[0];
        int j2 = bad[1];
        if(j1 >= lo[j2] && j1 <= hi[j2] && j2 >= lo[j1] && j2 <= hi[j1]) cout << j1 + 1 << " " << j2 + 1 << "\n";
        else cout << -1 << "\n";
        return;
    }
    else if(bad.size() == 0){
        cout << 1 << " " << 1 << "\n";
        return;
    }
    else{
        int j1 = bad[0];
        for(int j=0;j<m;j++){
            if(j == j1) continue;
            int j2 = j;
            if(j1 >= lo[j2] && j1 <= hi[j2] && j2 >= lo[j1] && j2 <= hi[j1]){
                cout << j1 + 1 << " " << j2 + 1 << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}