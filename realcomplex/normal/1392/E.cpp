#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair

int main(){
    int n;
    cin >> n;
    vector<vector<ll>> q(n);
    int id = 49;
    int p;
    int lg;
    for(int i = 0 ;i  < n; i ++ ){
        q[i].resize(n);
        for(int j = 0 ; j < n; j ++ ){
            if(i + j == 0 || i + j == 2 * n - 2) continue;
            p = (i + j) - 1;
            lg = id-p;
            if(j%2 == 0){
                q[i][j] = (1ll << lg);
            }
        }
    }
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            cout << q[i][j] << " ";
        }
        cout << endl;
    }
    int qr;
    cin >> qr;
    ll sum;
    int cur;
    for(int i = 0; i < qr; i ++ ){
        cin >> sum;
        int ci = 0, cj = 0;
        vector<pii> sol = {mp(0, 0)};
        cur = id;
        for(int i = 0 ; i < 2 * n - 2; i ++ ){
            if(ci == n-1) cj ++ ;
            else if(cj == n-1) ci ++ ;
            else{
                if((sum & (1ll << cur))){
                    if(q[ci+1][cj] == (1ll << cur)){
                        ci++;
                    }
                    else{
                        cj++;
                    }
                }
                else{
                    if(q[ci+1][cj] == 0){
                        ci ++ ;
                    }
                    else{
                        cj ++ ;
                    }
                }
            }
            sol.push_back(mp(ci, cj));
            cur -- ;
        }
        for(auto x : sol){
            cout << x.fi+1 << " " << x.se+1 << endl;
        }
    }
    return 0;
}