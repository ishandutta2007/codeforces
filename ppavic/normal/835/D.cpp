#include <cstdio>
#include <iostream>

using namespace std;

typedef long long int llint;


const int N = 5005;
const llint MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const llint base = 31337;


llint pot[N],roll[N][3],sol[N],n,dp[N][N];
string s;

inline llint aaa(llint x){
    if(x < 0) return x + MOD;
    return x;
}

void pre(){
    pot[0] = 1;
    for(int i = 1;i<=n;i++){
        pot[i] = pot[i-1] * base % MOD;
    }

    for(int i = 0;i<n;i++){
        roll[i+1][0] = (roll[i][0] + s[i] * pot[i] % MOD) % MOD;
    }
    for(int i = n-1;i>=0;i--){
        roll[i+1][1] = (roll[i+2][1] + s[i] * pot[n-1-i] % MOD) % MOD;
    }
}

llint gethsh(int i,int j,int sm){
    if(!sm){
        return aaa(roll[j][sm] - roll[i-1][sm]) * pot[n - j + 1] % MOD;
    }
    else{
        return aaa(roll[i][sm] - roll[j+1][sm]) * pot[i] % MOD;
    }
}

llint checkpalin(int i,int j){
    return gethsh(i,j,0) == gethsh(i,j,1);
}

void prijelaz(int i,int j){
    llint raz;
    if((j-i)%2 && gethsh(i,(i+j)/2,0) == gethsh((i+j)/2+1,j,0)){
        raz = dp[i][(i+j)/2] + 1;
    }
    else if(gethsh(i,(i+j)/2-1,0) == gethsh((i+j)/2+1,j,0)){
        raz = dp[i][(i+j)/2-1] + 1;
    }
    else{
        raz = 1;
    }
    dp[i][j] = raz;
    sol[dp[i][j] - 1]++;
}

int main(){
    cin >> s;
    n = s.size();
    pre();
    for(int i = 1;i<=n;i++){
        for(int j = 0;i+j<=n;j++){
            if(!checkpalin(i,i+j)) continue;
            prijelaz(i,i+j);
        }
    }
    int c = 0;
    for(int i = n;i>=0;i--){
        c += sol[i];
        sol[i] = c;
    }
    for(int i = 0;i<n;i++){
        printf("%d ",sol[i]);
    }
    printf("\n");
}