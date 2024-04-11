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
int n,a[MAXN];
int x[MAXN],y[MAXN];

int main(){
    scanf("%d",&n);
    if(n == 1){
        puts("1 1");
        return 0;
    }
    if(n == 2){
        puts("1 1 2 2");
        return 0;
    }
    a[1] = 1;a[n] = 1;a[n+2] = 2;a[2*n] = 2;
    int l1 = 2,r1 = n-1,l2 = n+3,r2 = 2*n-1;
    FOR(i,3,n-1){
        if(i&1){
            a[l1++] = i;
            a[r1--] = i;
        }
        else{
            a[l2++] = i;
            a[r2--] = i;
        }
    }
    FOR(i,1,2*n) if(!a[i]) a[i] = n;
    FOR(i,1,2*n){
        if(!x[a[i]]) x[a[i]] = i;
        else y[a[i]] = i;
    }
    FOR(i,1,n-1){
        assert(y[i]-x[i]==n-i);
    }
    FOR(i,1,2*n) printf("%d ",a[i]);puts("");
    return 0;
}