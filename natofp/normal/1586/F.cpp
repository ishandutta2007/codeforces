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

const int nax = 1005;

int n, k;
int col[nax][nax];
int c = 0;
vector<int> g(int x){
    vector<int> ans;
    for(int i=0;i<c;i++){
        ans.pb(x % k);
        x /= k;
    }
    return ans;
}

vector<int> repr[nax];

void solve(){
    cin >> n >> k;
    int tmp = 1;
    while(tmp < n){
        tmp *= k;
        c += 1;
    }
    repr[1] = g(0);
    for(int i=2;i<=n;i++){
        auto cur = g(i - 1);
        repr[i] = cur;
        vector<bool> done(c, false);
        for(int j=0;j<cur.size();j++){
            if(cur[j] == 0) done[j] = true;
        }
        for(int j=i-1;j>=1;j--){
            bool was = false;
            for(int k=c-1;k>=0;k--){
                if(done[k]) continue;
                if(repr[j][k] + 1 == repr[i][k]){
                    was = true;
                    col[j][i] = k;
                    done[k] = true;
                    break;
                }
            }
            if(!was){
                for(int k=c-1;k>=0;k--){
                    if(repr[j][k] + 1 <= repr[i][k]){
                        col[j][i] = k;
                        break;
                    }
                }
            }
        }
    }
    cout << c << "\n";
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            cout << col[i][j] + 1 << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}