#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
int a[MAXN],pre[MAXN],n,m;

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) pre[i] = a[i]==a[i-1]?pre[i-1]:i-1;
    FOR(i,1,m){
        int l,r,x;scanf("%d%d%d",&l,&r,&x);
        if(a[r] != x){
            printf("%d\n",r);
        }
        else if(pre[r] >= l){
            printf("%d\n",pre[r]);
        }
        else{
            puts("-1");
        }
    }
    return 0;
}