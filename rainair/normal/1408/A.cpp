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

const int MAXN = 100+5;
int a[MAXN],b[MAXN],c[MAXN],n;
int d[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",a+i);
        FOR(i,1,n) scanf("%d",b+i);
        FOR(i,1,n) scanf("%d",c+i);
        d[1] = a[1];
        FOR(i,2,n-1){
            if(a[i] != d[i-1]) d[i] = a[i];
            else if(b[i] != d[i-1]) d[i] = b[i];
            else d[i] = c[i];
        }
        if(a[n] != d[n-1] && a[n] != d[1]) d[n] = a[n];
        else if(b[n] != d[n-1] && b[n] != d[1]) d[n] = b[n];
        else d[n] = c[n];
        FOR(i,1,n) printf("%d ",d[i]);puts("");
    }
    return 0;
}