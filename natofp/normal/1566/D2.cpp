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

const int nax = 305;
const int inf = 1e9;

int sala[nax][nax];
int ty[nax][nax];

void solve(){
    int n, m; cin >> n >> m;
    vector<pii> a;
    for(int i=0;i<n*m;i++){
        int x; cin >> x;
        a.pb(mp(x, i));
    }
    sort(a.begin(), a.end());
    int done = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sala[i][j] = a[done].nd;
            ty[i][j] = a[done++].st;
        }
    }
    int ac = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<j;k++){
                if(sala[i][k] < sala[i][j]) ac++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=1;j<=m;j++){
            if(ty[i][j] == ty[i][j - 1]){
                ac -= cnt;
                cnt++;
            }
            else{
                cnt = 1;
            }
        }
    }
    cout<<ac<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}