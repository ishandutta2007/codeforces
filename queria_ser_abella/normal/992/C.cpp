#include <bits/stdc++.h>
#define maxn 300300
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define mod 1000000007
using namespace std;

struct mat {
    ll M[2][2];
    mat(){
        memset(M,0,sizeof(M));
    }
    mat operator*(mat t){
        mat r;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++){
                    r.M[i][j] += M[i][k] * t.M[k][j];
                    r.M[i][j] %= mod;
                }
        return r;
    }
};

mat id(){
    mat r;
    r.M[0][0] = r.M[1][1] = 1;
    return r;
}

mat exp(mat a,ll k){
    if(k == 0) return id();
    mat r = exp(a,k/2);
    r = r*r;
    if(k&1) r = r*a;
    return r;
}

int main(){
    
    ll n,k;
    scanf("%lld%lld",&n,&k);
    if(n == 0){
        printf("0\n");
        exit(0);
    }
    n = (n*2)%mod;
    
    mat A;
    A.M[0][0] = 2;
    A.M[1][0] = -1;
    A.M[0][1] = 0;
    A.M[1][1] = 1;A = exp(A,k);
   // printf("%lld %lld\n%lld %lld\n\n",A.M[0][0],A.M[0][1],A.M[1][0],A.M[1][1]);
    
    ll ans = (n*A.M[0][0]+A.M[1][0]) % mod;
    if(ans < 0)
        ans += mod;
    printf("%lld\n",ans);

}