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

const int N = 51;
const int MOD = (int)1e9 + 7;

void add(int &a, int b){    
    a += b;
    if(a >= MOD)
        a -= MOD;
}

int mult(int a, int b){
    return (a * 1ll * b) % MOD;
}
int dp[2][N][N][N][N];

// dp[i][last - 1][last - 2][this - 1][this - 2]

void bad(){
    cout << 0;
    exit(0);
}

int compute(int a){
    return a*(a-1)/2;
}

int main(){
    fastIO;
    int n;
    cin >> n;
    int d1, d2;
    cin >> d1 >> d2;
    int nd;
    if(d1 == 2){
        dp[1][1][0][(d2==2)][(d2==3)] = 1;
    }
    else{
        if(n == 3)
            bad();
        dp[1][0][1][(d2==2)][(d2==3)] = 1;
    }
    int bit = 0;
    
    int dd;
    int nx, ny, np, nq;
    int res;
    for(int i = 2; i < n; i ++ ){
        cin >> dd;
        for(int x = 0 ; x <= n ; x ++ )
            for(int y = 0 ;x + y <= n; y ++ ){
                for(int p = 0; x + y + p <= n; p ++ ){
                    for(int q = 0 ; x + y + p + q <= n; q ++ ){
                        for(int par = 1; par <= 2; par ++ ){
                            for(int n1 = 0 ; n1 < 3; n1 ++ ){
                                for(int n2 = n1 ; n2 < 3; n2 ++ ){
                                    if((n1 > 0) + (n2 > 0) + 1 > dd){
                                        continue;
                                    }
                                    nx = x, ny = y, np = p, nq = q;
                                    res = dp[!bit][x][y][p][q];
                                    if(res == 0)
                                        continue;
                                    if(par == 1) res = mult(res, x), nx -- ;
                                    else res = mult(res, y), ny -- , nx ++;
                                    if(nx < 0 || ny < 0)
                                        continue;
                                    if(n2 > 0){
                                        if(n1 == 0){
                                            if(n2 == 1) 
                                                res = mult(res, p),np--;
                                            else
                                                res = mult(res, q),nq--,
                                                np++;
                                            if(np < 0 || nq < 0)
                                                continue;
                                        }
                                        else if(n1 == n2){
                                            if(n1 == 1){
                                                res = mult(res, compute(p));
                                                np -= 2;
                                            }
                                            else{
                                                res = mult(res, compute(q));
                                                nq -= 2;
                                                np += 2;
                                            }
                                            if(np < 0 || nq < 0)
                                                continue;
                                        }
                                        else{
                                            res = mult(res, p * q);
                                            np -- ;
                                            nq -- ;
                                            if(np < 0 || nq < 0)
                                                continue;
                                            np ++ ;
                                        }
                                    }
                                    nd = dd;
                                    nd -- ;
                                    nd -= (n1 > 0);
                                    nd -= (n2 > 0);
                                    if(nd == 1) np ++ ;
                                    if(nd == 2) nq ++ ;
                                    add(dp[bit][nx][ny][np][nq], res);
                                }
                            }
                        }
                    }
                }
            }
        for(int x = 0 ; x <= n; x ++ )
            for(int y = 0 ; y <= n; y ++ ){
                if(x > 0 || y > 0)
                    add(dp[bit][x][y][0][0], dp[bit][0][0][x][y]);
            }
        bit ^= 1;
        for(int x = 0 ; x <= n; x ++ ) for(int y = 0 ; x + y <= n; y ++ )
            for(int p = 0; x + y + p <= n; p ++ ) for(int q = 0 ; x + y + p + q <= n ;q ++ )
                dp[bit][x][y][p][q] = 0;
    }
    cout << dp[!bit][0][0][0][0];
    return 0;
}