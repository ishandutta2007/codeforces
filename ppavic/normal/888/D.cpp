#include <cstdio>

using namespace std;

typedef long long int llint;

const int N = 1005;
const int K = 10;

llint n,k;
llint chs[N][K];
llint chs2[N][K];

llint fak[K];
llint der[K] = {1,0,1,2,9,44};

void komb(){
    fak[0] = 1;
    for(int i = 1;i<K;i++){
        fak[i] = fak[i-1] * i;
    }
    for(int i = 0;i<N;i++){
        chs2[i][0] = 1;
        chs[i][0] = 1;
        for(int j = 1;j<K;j++){
            chs2[i][j] = chs2[i][j-1] * (i - j + 1);
            chs[i][j]  = chs2[i][j] / fak[j];
        }
    }
}

int main(){
    komb();
    scanf("%I64d%I64d",&n,&k);
    llint sol = 1;
    for(int i = 1;i<=k;i++){
        sol += chs[n][i] * der[i];
    }
    printf("%I64d\n",sol);
}