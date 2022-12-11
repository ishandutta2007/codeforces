#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ ){
        int n, k;
        cin >> n >> k;
        int a[n][n];
        vector<pair<int, pii>> sh;
        for(int i = 0 ; i < n ; i ++ ){
            for(int j = 0; j  < n; j ++ ){
                a[i][j] = 0;
                sh.push_back(mp((i - j + n) % n, mp(i,j)));
            }
        }
        sort(sh.begin(), sh.end());
        for(int i = 0 ; i < k ; i ++ ){

            a[sh[i].se.fi][sh[i].se.se] = 1;
        }
        if(k % n == 0)
            cout << 0 << "\n";
        else
            cout << 2 << "\n";
        for(int i = 0 ; i < n; i ++ ){
            for(int j = 0 ; j < n; j ++ ){
                cout << a[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}