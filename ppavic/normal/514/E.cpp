#include <cstdio>

using namespace std;

typedef long long int llint;

const llint BIG = 1e5 + 500;
const llint maxN = 150;
const llint N = 105;
const llint MOD = 1e9 + 7;

llint n,k;
llint mat[maxN][maxN],d[BIG],st[maxN][maxN],sol[maxN][maxN],tmp[maxN][maxN],tmp2[maxN][maxN],tmp3[maxN][maxN];

llint mul(llint A,llint B){
    return A * B % MOD;
}

llint add(llint A,llint B){
    if(A+B > MOD) return A + B - MOD;
    return A + B;
}

llint addto(llint A,llint B,llint C){
    return add(A,mul(B,C));
}

void pot(int eks){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            tmp[i][j] = mat[i][j];
        }
    }
    for(int i = 0;i<N;i++)
        sol[i][i] = 1;
    while(eks >  0){
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                tmp2[i][j] = tmp[i][j];
                tmp3[i][j] = sol[i][j];
            }
        }
        if(eks&1){
            for(int i = 0;i<N;i++){
                for(int j = 0;j<N;j++){
                    sol[i][j] = 0;
                    for(int k = 0;k<N;k++){
                        sol[i][j] = addto(sol[i][j],tmp3[i][k],tmp[k][j]);
                    }
                }
            }

        }
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                tmp[i][j] = 0;
                for(int k = 0;k< N ;k++){
                    tmp[i][j] = addto(tmp[i][j],tmp2[i][k],tmp2[k][j]);
                }
            }
        }
        eks /= 2;

    }
}

int main() {
    scanf("%I64d %I64d",&n,&k);
    for(int i = 0;i<100;i++){
        mat[i][i+1] = 1;
    }
    mat[0][101] = 1;
    mat[101][101] = 1;
    for(int i = 0;i<n;i++){
        scanf("%d",&d[i]);
        mat[d[i]-1][0]++;
    }
    pot(k+1);
    printf("%I64d\n",sol[0][101] % MOD);
}