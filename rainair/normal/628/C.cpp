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

const int MAXN = 1e5 + 5;
int n;char a[MAXN],b[MAXN];
int k;

int main(){
    scanf("%d%d",&n,&k);int kk = k;
    scanf("%s",a+1);
    FOR(i,1,n){
        int l1 = a[i]-'a',l2 = 'z'-a[i];
        int t = std::min(std::max(l1,l2),k);
        if(l1 <= l2){
            b[i] = a[i]+t;
        }
        else{
            b[i] = a[i]-t;
        }
        k -= t;
    }
    if(k)puts("-1");
    else{
        int ans = 0;
        FOR(i,1,n) ans += std::abs(a[i]-b[i]);
        assert(ans==kk);
        FOR(i,1,n) putchar(b[i]);puts("");
    }
    return 0;
}