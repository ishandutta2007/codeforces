#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int f[35][35][55];

inline int dp(int i,int j,int k){
    if(k > i*j) return 1e9;
    if(k == i*j) return 0;
    if(!k) return 0;
    if(f[i][j][k] != -1) return f[i][j][k];
    int &res = f[i][j][k];res = 1e9;
    FOR(x,0,k){
        FOR(y,1,i-1) res = std::min(res,dp(y,j,x)+dp(i-y,j,k-x)+j*j);
        FOR(y,1,j-1) res = std::min(res,dp(i,y,x)+dp(i,j-y,k-x)+i*i);
    }
    return res;
}

int main(){
    CLR(f,-1);
    int T;scanf("%d",&T);
    while(T--){
        int n,m,k;scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",dp(n,m,k));
    }
    return 0;
}