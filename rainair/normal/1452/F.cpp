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
#define int LL

const int MAXN = 50+5;
LL a[MAXN],b[MAXN];
int n,q;

inline int solve(int x,LL y){
    LL r = 0;
    FOR(i,1,x) r += a[i];
    r = y-r;
    if(r <= 0) return 0;
    LL ans = 0;
    FOR(i,x+1,n){
        LL c = 1ll<<(i-x);
        if(c*a[i] <= r){
            r -= c*a[i];
            a[x] += c*a[i];
            ans += (c-1)*a[i];
            a[i] = 0;
        }
        else{
            LL d = r/c;
            r -= c*d;
            a[i] -= d;
            a[x] += c*d;
            ans += (c-1)*d;
        }
    }
    if(!r) return ans;
    LL ext = 0;
    FOR(i,2,x) ext += a[i]*((1ll<<(i-1))-1);
    if(ext >= r) return ans+r;
    int ps = -1;
    FOR(i,x+1,n) if(a[i]){ps = i;break;}
    if(ps == -1) return -1;
    a[ps-1] += 2;a[ps]--;++ans;
    if(ps-1 == x) ext += 2*((1ll<<(x-1))-1),r -= 2;
    ROF(i,ps-1,x+1){
        LL c = 1ll<<(i-x);
        if(c <= r){
            r -= c;
            ans += c-1;
            a[x] += c;ext += c*((1ll<<(x-1))-1);
            if(r <= ext) return ans+r;
        }
        ++ans;a[i]--;a[i-1] += 2;
        if(i-1 == x) ext += 2*((1ll<<(x-1))-1),r -= 2;
    }
    r = std::max(r,0ll);
    if(r <= ext) ans += r,r = 0;
    else return -1;
    return ans;
}

signed main(){
//    freopen("F.in","r",stdin);
    //freopen("F.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    FOR(i,1,n) scanf("%lld",a+i);
    int c = 0;
    FOR(i,1,q){
        int opt,x;LL y;scanf("%lld%lld%lld",&opt,&x,&y);++x;
        if(opt == 1){
            a[x] = y;
        }
        if(opt == 2){
            FOR(i,0,n) b[i] = a[i];
            printf("%lld\n",solve(x,y));
            FOR(i,0,n) a[i] = b[i];
        }
    }
    return 0;
}