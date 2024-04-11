#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5000+5;
int n,m;
char A[MAXN],B[MAXN];
int f[MAXN][MAXN];

int main(){
    scanf("%d%d",&n,&m);
    scanf("%s%s",A+1,B+1);
    int ans = 0;
    FOR(i,1,n){
        FOR(j,1,m){
            f[i][j] = std::max({0,f[i-1][j]-1,f[i][j-1]-1,A[i]==B[j]?f[i-1][j-1]+2:-1000000000});
            ans = std::max(ans,f[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}