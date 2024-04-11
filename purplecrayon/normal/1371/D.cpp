#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
const int MAXN = 310, ALP = 26, MAXL = 20, INF = 1e9+10;

int res[MAXN][MAXN];

void solve(){
    int n, k; cin >> n >> k;
    cout << (k%n?2:0) << "\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) res[i][j] = 0;
    }
    int p=0, q=0;
    while(k>0){
        k--;
        res[p][q]=1;
        p++;q++;q%=n;
        if(p==n){
            p=0;q++;q%=n;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) cout << res[i][j];
        cout << "\n";
    }
}
int main(){
    int t=0; cin >> t;
    while (t--) solve();
}