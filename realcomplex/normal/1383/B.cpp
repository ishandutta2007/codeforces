#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> A[i];
    }
    int cnt;
    for(int lg = 30; lg >= 0 ; lg -- ){
        cnt = 0;
        for(int i = 0 ; i < n; i ++ ){
            if((A[i] & (1ll << lg)))
                cnt ++ ;
        }
        if(cnt % 2 == 0) continue;
        if((n - cnt) % 2 == 1){
            cout << "WIN\n";
        }
        else{
            if(((cnt - 1) / 2) % 2 == 0)
                cout << "WIN\n";
            else
                cout << "LOSE\n";
        }
        return;
    }
    cout << "DRAW\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t =0 ; t < tc; t ++ ){
        solve();
    }
    return 0;
}