#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int testc;
    cin >> testc;
    for(int t = 0 ;t < testc; t ++ ){
        int n, m;
        cin >> n >> m;
        int f[n][m];
        int k1[n];
        int k2[m];
        char q;
        for(int i = 0 ; i < n; i ++ ){
            for(int j = 0 ; j < m ; j ++ ){
                cin >> q;
                if(q == '*') f[i][j] = 1;
                else f[i][j] = 0;
            }
        }
        for(int i = 0 ;i  < n; i ++ )k1[i] = 0;
        for(int i = 0 ; i < m ; i ++ )k2[i] = 0;
        for(int i = 0 ;i  < n; i ++ ){
            for(int j = 0 ;j  < m ; j ++ ){
                k1[i] += f[i][j];
                k2[j] += f[i][j];
            }
        }
        int p1, p2;
        int res = n + m - 1;
        int y;
        for(int i = 0 ; i < n; i ++ ){
            for(int j = 0 ; j < m ; j ++ ){
                p1 = k1[i];
                p2 = k2[j];
                if(f[i][j] == 1) p1 -- , p2 -- ,y = 1;
                else y = 0;
                res = min(res, n + m - 1 - (p1 + p2 + y));
            }
        }
        cout << res << "\n";
    }
    return 0;
}