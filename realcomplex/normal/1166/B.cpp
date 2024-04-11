#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

int main(){
    fastIO;
    string base = "aeiou";
    int k;
    cin >> k;
    int r, c;
    for(int i = 5; i <= k ; i ++ ){
        r = i;
        if(k % i == 0){
            c = k/i;
            if(c >= 5){
                char nw;
                char res[r][c];
                for(int j = 0 ; j < c; j ++ ){
                    nw = base[4];
                    base.pop_back();
                    base = nw + base;
                    for(int z = 0 ; z < 5; z ++ )
                        res[z][j] = base[z];
                }
                for(int j = 5; j < r; j ++ ){
                    for(int z = 0 ; z < c; z ++ ){
                        res[j][z] = base[z % 5];
                    }
                }
                for(int j = 0 ; j < r; j ++ ){
                    for(int z = 0 ; z < c; z ++ ){
                        cout << res[j][z];
                    }
                }
                exit(0);
            }
        }
    }
    cout << -1;
    return 0;
}