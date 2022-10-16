#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 5005;
const int MOD = 998244353;

typedef long long int llint;

llint a,b,c;
llint povrh[N][N];
llint fak[N];

llint s1,s2,s3;



void comp(){
    fak[0] = 1;
    povrh[1][1] = 1;
    povrh[1][0] = 1;
    for(int j = 1;j<N;j++)
        fak[j] = fak[j - 1] * j %  MOD;
    for(int n = 2;n<N;n++){
        povrh[n][0] = 1;
        povrh[n][n] = 1;
        for(int k = 1;k<n;k++){
            povrh[n][k] = (povrh[n-1][k-1] + povrh[n-1][k]) % MOD;
        }
    }
}


int main(){
    comp();
    scanf("%I64d%I64d%I64d",&a,&b,&c);
    for(int x = 0;x<=min(a,b);x++){
        s1 = (s1 + povrh[a][x] * povrh[b][x] % MOD * fak[x] % MOD) % MOD;
    }
    for(int x = 0;x<=min(a,c);x++){
        s2 = (s2 + povrh[a][x] * povrh[c][x] % MOD * fak[x] % MOD) % MOD;
    }
    for(int x = 0;x<=min(b,c);x++){
        s3 = (s3 + povrh[b][x] * povrh[c][x] % MOD* fak[x] % MOD) % MOD;
    }
    printf("%I64d\n",((s1 * s2) % MOD * s3) % MOD);
}