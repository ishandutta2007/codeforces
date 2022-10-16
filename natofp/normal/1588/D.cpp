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

const int nax = 10;
int dp[nax * nax + nax][1 << nax];
pii pr[nax * nax + nax][1 << nax];
int n;

string s[nax];

int pozycja[2][11][300];

void solve(){
    for(int i=0;i<2;i++){
        for(int j=0;j<11;j++){
            for(int k=0;k<300;k++){
                pozycja[i][j][k] = -1;
            }
        }
    }

    cin >> n;

    for(int i=0;i<n;i++) cin >> s[i];

    for(int i=0;i<n;i++){
        vector<int> cnt(333, 0);
        for(int j=0;j<s[i].size();j++){
            char akt = s[i][j];
            pozycja[cnt[akt]][i][akt] = j;
            cnt[akt] += 1;
        }
    }

    for(int i=0;i<nax*nax+nax;i++){
        for(int j=0;j<(1<<nax);j++){
            dp[i][j] = -1e9;
            pr[i][j] = mp(-1, -1);
        }
    }
    int ac = 0;
    pii from = mp(-1, -1);
    for(int i=0;i<s[0].size();i++){
        char cur = s[0][i];
        bool ex = true;
        for(int j=0;j<n;j++){
            bool jest = false;
            for(char x : s[j]){
                if(x == cur) jest = true;
            }
            if(!jest) ex = false;
        }
        if(ex){
            dp[i][0] = 1;
            ac = 1;
            from = mp(i, 0);
        }
    }

    for(int i=0;i<s[0].size();i++){
        for(int j=0;j<(1<<n);j++){
            if(dp[i][j] < 0) continue;
            vector<int> pos;
            for(int k=1;k<n;k++){
                if(j & (1 << k)) pos.pb(1);
                else pos.pb(0);
            }
            bool dbg = (i == 0 && j == 0);
            for(int to=i+1;to<s[0].size();to++){
                char go = s[0][to];
                char cur = s[0][i];
                bool can = true;
                int nxtMask = 0;
                for(int k=1;k<n;k++){
                    int startPos = pozycja[pos[k - 1]][k][cur];

                    int mini = 1e9;
                    for(int c=0;c<2;c++){
                        if(pozycja[c][k][go] > startPos){
                            mini = min(mini, c);
                        }
                    }
                    if(mini == 1e9) can = false;
                    else if(mini == 1){
                        nxtMask |= (1 << k);
                    }
                }

                if(can && dp[i][j] + 1 > dp[to][nxtMask]){
                    dp[to][nxtMask] = max(dp[to][nxtMask], dp[i][j] + 1);
                    pr[to][nxtMask] = mp(i, j);
                    if(dp[to][nxtMask] > ac){
                         ac = max(ac, dp[to][nxtMask]);
                         from = mp(to, nxtMask);
                    }


                }
            }
        }
    }
    cout << ac << "\n";
    vector<char> essa;
    while(from != mp(-1, -1)){
        essa.pb(s[0][from.st]);
        from = pr[from.st][from.nd];
    }
    reverse(essa.begin(), essa.end());
    for(char x : essa) cout << x;
    cout << "\n";
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}