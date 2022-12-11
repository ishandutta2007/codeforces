#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 81;
const int M = N*(N+1)/2;
short dp[N][N][M];

void upd(short &x, short y){
    x=min(x,y);
}

int outp[M];

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<int> xx(n);
    int c0 = 0, c1 = 0;
    for(int i = 0 ;i  < n; i ++ ){
        cin >> xx[i];
        if(xx[i] == 0) c0 ++ ;
        else c1 ++ ;
    }
    for(int i = 0 ; i < N; i ++ ){
        for(int j = 0 ; j < N ; j ++ ){
            for(int d = 0; d < M; d ++ ){
                dp[i][j][d]=20000;
            }
        }
    }
    int m = n * (n - 1) / 2;
    if(c1 == 0){
        for(int j = 0 ; j <= m ; j ++ ) cout << 0 << " ";
        cout << "\n";
        return 0;
    }
    dp[0][0][0]=0;
    int s0, s1;
    int d0, d1;
    int fir;
    int opr;
    short old;
    int extra;
    for(int x = 0; x <= c0; x ++ ){
        for(int y = 0; y < c1; y ++ ){
            for(int sor = 0; sor <= m; sor ++ ){
                if(dp[x][y][sor] == 20000){ // most states are unreachable
                    continue;
                }
                old = dp[x][y][sor];
                vector<int> nw;
                fir = -1;
                d0 = x;
                d1 = y;
                for(int k = 0 ; k < n; k ++ ){
                    if(xx[k] == 0){
                        if(d0 > 0) d0 -- ;
                        else{
                            nw.push_back(0);
                        }
                    }
                    else{
                        if(d1 > 0) d1 -- ;
                        else{

                            if(fir == -1) fir = nw.size();
                            nw.push_back(1);
                        }
                    }
                }
                opr = 0;
                s0 = 0;
                s1 = 0;
                upd(dp[x][y+1][sor+fir], old);
                for(int k = 0 ; k < nw.size(); k ++ ){
                    if(nw[k] == 0){
                        s0 ++ ;
                        opr += s1;
                    }
                    else{
                        s1 ++ ;
                    }
                    if(s0 > 0){
                        extra = 0;
                        if(s1 == 0) extra = fir - k - 1;
                        upd(dp[x+s0][y+1][sor+extra+opr], old+s0*(s0-1)/2);
                    }
                }
            }
        }
    }
    for(int i = 0 ; i <= c0; i ++ ){
        for(int j = 0 ; j <= m; j ++ ){
            outp[j] = max(outp[j], c0*(c0-1)/2 - (dp[i][c1][j] + (c0 - i) * (c0 - i - 1) / 2));
        }
    }
    for(int j = 0; j <= m ; j ++ ){
        if(j) outp[j]=max(outp[j],outp[j-1]);
        cout << outp[j] << " ";
    }
    return 0;
}