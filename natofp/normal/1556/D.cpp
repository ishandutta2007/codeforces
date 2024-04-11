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

const int nax = 10005;

int andans[nax];
int orans[nax];

int orASK(int i, int j){
    cout << "or " << i << " " << j << endl;
    fflush(stdout);
    int x; cin >> x;
    return x;
}

int andASK(int i, int j){
    cout << "and " << i << " " << j << endl;
    fflush(stdout);
    int x; cin >> x;
    return x;
}

int n, k;

int help;

int bit[nax][30];

void solve(){
    cin >> n >> k;
    for(int i=1;i<n;i++){
        andans[i] = andASK(i, i + 1);
        orans[i] = orASK(i, i + 1);
    }
    help = orASK(1, 3);
    for(int i=0;i<30;i++){
        for(int j=1;j<=n;j++) bit[j][i] = 2;
        bool ez = false;
        for(int j=1;j<n;j++){
            if(andans[j] & (1 << i)){
                bit[j][i] = 1;
                bit[j + 1][i] = 1;
                ez = true;
            }
            if((orans[j] & (1 << i)) == 0){
                bit[j][i] = 0;
                bit[j + 1][i] = 0;
                ez = true;
            }
        }

        if(!ez){
            if(help & (1 << i)){
                bit[1][i] = 1;
                bit[3][i] = 1;
            }
            else{
                bit[1][i] = 0;
                bit[3][i] = 0;
            }
        }
        int pos = -1;
        for(int j=1;j<=n;j++){
            if(bit[j][i] != 2) pos = j;
        }

        for(int j=pos+1;j<=n;j++){
            if(bit[j - 1][i] == 0){
                if((orans[j - 1] & (1 << i)) == 0){
                    bit[j][i] = 0;
                }
                else bit[j][i] = 1;
            }
            else{
                if(andans[j - 1] & (1 << i)){
                    bit[j][i] = 1;
                }
                else bit[j][i] = 0;
            }
        }

        for(int j=pos-1;j>=1;j--){
            if(bit[j + 1][i] == 0){
                if((orans[j] & (1 << i)) == 0){
                    bit[j][i] = 0;
                }
                else bit[j][i] = 1;
            }
            else{
                if(andans[j] & (1 << i)){
                    bit[j][i] = 1;
                }
                else bit[j][i] = 0;
            }
        }
    }
    vector<int> nbr;
    for(int i=1;i<=n;i++){
        int cur = 0;
        for(int j=0;j<30;j++){
            if(bit[i][j]) cur += (1 << j);
        }
        nbr.pb(cur);
    }
    sort(nbr.begin(), nbr.end());
    cout << "finish " << nbr[k - 1] << endl;
    fflush(stdout);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}