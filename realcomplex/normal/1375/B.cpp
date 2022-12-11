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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> sol(n);
        int deg;
        bool has = true;
        for(int i = 0 ;i  < n; i ++ ){
            sol[i].resize(m);
            int cur;
            for(int j = 0 ; j < m ; j ++ ){
                cin >> cur;
                deg = 4;
                if(i == 0) deg -- ;
                if(i == n - 1) deg -- ;
                if(j == 0) deg -- ;
                if(j == m - 1) deg -- ;
                if(cur > deg){
                    has = false;
                }
                sol[i][j] = deg;
            }
        }
        if(has){
            cout << "YES\n";
            for(int i = 0 ; i < n; i ++ ){
                for(int j = 0 ; j < m ; j ++ ){
                    cout << sol[i][j] << " ";
                }
                cout << "\n";
            }
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}