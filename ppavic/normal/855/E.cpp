#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long int llint;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int M = 1124;
const int B = 12;
const int N = 65;

llint dp[B][N][M][2];

llint up[N],q,b,l,r;

llint f(int bs, int i, int msk, int fl,int poc){
    if(i == -1){
        return (msk == 0);
    }
    if(!fl && dp[bs][i][msk][poc] != -1) return dp[bs][i][msk][poc];
    int lim = bs - 1;
    llint ret = 0;
    if(fl)
        lim = up[i];
    for(int j = 0;j<=lim;j++){
        int nf = fl;
        if(j < up[i]) nf = 0;
        ret += f(bs, i - 1, ((j | poc) ? (msk ^ (1 << j)) : msk) , nf , j || poc);
    }
    if(!fl){
        dp[bs][i][msk][poc] = ret;
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> q;
    for(int i = 0;i<q;i++){
        cin >> b >> l >> r;
        for(int j = 0; j < N;j++){
            up[j] = int(r % (llint)b);
            r /= (llint)b;
        }
        l--;
        llint sol = f(b , N-1, 0, 1 , 0);
        for(int j = 0; j < N;j++){
            up[j] = int(l % (llint)b);
            l /= (llint)b;
        }
        sol -= f(b, N-1, 0, 1, 0);
        cout << sol << "\n";
    }
}