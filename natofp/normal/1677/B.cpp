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

const int nax = 1e6 + 5;
int col[nax];
int row[nax];
string s;
int n, m;
int ans[nax];
bool good[nax];
int pref[nax];
int act[nax];
int xd[nax];

void solve(){
    cin >> n >> m;
    cin >> s;
    int cnt = 0;
    fill(col + 1, col + n * m + 1, 0);
    fill(ans, ans + n * m + 1, 0);
    fill(xd, xd + n * m + 1, 0);
    int wsk = m;
    for(int i=0;i<n*m;i++){
        char x = s[i];
        if(x == '1'){
            col[wsk] += 1;
            if(col[wsk] == 1) cnt += 1;
        }
        wsk--;
        if(wsk == 0) wsk = m;
        ans[i + 1] += cnt;
    }
    pref[0] = (s[0] == '1');
    for(int i=1;i<n*m;i++){
        pref[i] = pref[i - 1] + (s[i] == '1');
    }
    for(int i=1;i<=n*m;i++){
        if(i <= m){
            xd[i] = (pref[i - 1] > 0);
        }
        else xd[i] = xd[i - m] + ((pref[i - 1] - pref[i - m - 1]) > 0);
        cout << ans[i] + xd[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}