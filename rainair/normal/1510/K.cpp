#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5+5;
int n,a[MAXN],b[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,2*n) scanf("%d",a+i),b[i ]= a[i];
    int ans = 1e9;
    FOR(i,1,4000){
        bool flag = 1;
        FOR(i,1,2*n) flag &= (b[i] == i);
        if(flag){
            ans = std::min(ans,i-1);
            break;
        }
        if((i&1)){
            FOR(i,1,n) std::swap(b[i],b[i+n]);
        }
        else{
            FOR(i,1,n) std::swap(b[i*2],b[i*2-1]);
        }
    }
    FOR(i,1,2*n) b[i] = a[i];
    FOR(i,1,4000){
        bool flag = 1;
        FOR(i,1,2*n) flag &= (b[i] == i);
        if(flag){
            ans = std::min(ans,i-1);
            break;
        }
        if(!(i&1)){
            FOR(i,1,n) std::swap(b[i],b[i+n]);
        }
        else{
            FOR(i,1,n) std::swap(b[i*2],b[i*2-1]);
        }
    }
    printf("%d\n",ans==1e9?-1:ans);
    return 0;
}