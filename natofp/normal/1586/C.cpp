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

int n, m;
vector<vector<char> > s;
vector<int> bad;

void solve(){
    cin >> n >> m;
    s.resize(n);
    for(int i=0;i<n;i++) s[i].resize(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> s[i][j];
    }
    for(int j=1;j<m;j++){
        int was = false;
        for(int i=1;i<n;i++){
            if(s[i - 1][j] == 'X' && s[i][j - 1] == 'X') was = true;
        }
        if(was) bad.pb(j);
    }
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        if(bad.size() == 0){
            cout << "YES" << "\n";
        }
        else{
            auto it = lower_bound(bad.begin(), bad.end(), x);
            if(it == bad.end()){
                cout << "YES" << "\n";
            }
            else{
                int w = (*it);
                if(w < y) cout << "NO" << "\n";
                else cout << "YES" << "\n";
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