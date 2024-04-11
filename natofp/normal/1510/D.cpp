#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
using namespace std;

const int nax = 1e5 + 5;

ld dp[nax][10];
pii pop[nax][10];
int a[nax];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d; cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<nax;i++){
        for(int j=0;j<10;j++) dp[i][j] = -1e9;
    }
    dp[0][1] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            if(dp[i][j] < -1) continue;
            int to = (j * (a[i + 1]) % 10);
            ld cur = log(a[i + 1]);
            if(dp[i][j] + cur >= dp[i + 1][to]){
                dp[i + 1][to] = dp[i][j] + cur;
                pop[i + 1][to] = mp(a[i + 1], j);
            }
            if(dp[i][j] > dp[i + 1][j]){
                dp[i + 1][j] = dp[i][j];
                pop[i + 1][j] = mp(-1, j);
            }
        }
    }
    if(dp[n][d] < -1){
        cout << -1 << "\n";
        return 0;
    }
    vector<int> ans;
    int cur = d;
    int id = n;
    while(id >= 1){
        if(pop[id][cur].st != -1){
            ans.pb(pop[id][cur].st);
        }
        cur = pop[id][cur].nd;
        id--;
    }
    if(ans.size() == 0){
        cout << -1 << "\n";
        return 0;
    }
    cout << ans.size() << "\n";
    for(int x :ans ) cout << x << " " ;


    return 0;
}