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

const int MAXN = 5e5 + 5;

int x[MAXN],y[MAXN];
int n;
char str[MAXN];
int ansx,ansy;
// -3 2 -4 1 -3 -5
inline bool chk(int k){
    int lx=0,rx = 1e9,ly = 0,ry = 1e9,lxy = -1e9,rxy = 1e9;ansx = ansy = -1;
    FOR(i,1,n) lx = std::max(lx,x[i]-k),rx = std::min(rx,x[i]+k),
        ly = std::max(ly,y[i]-k),ry = std::min(ry,y[i]+k),
        lxy = std::max(lxy,x[i]-y[i]-k),rxy = std::min(rxy,x[i]-y[i]+k);
    if(lx <= rx && ly <= ry && lxy <= rxy){
        int ll = lx-ry,rr = rx-ly;
        FOR(y,ly,ry){
            int llx = std::max({lx,lxy+y,ll+y}),rrx = std::min({rx,rxy+y,rr+y});
            if(llx <= rrx && (y || rrx > 0)){
                ansx = rrx;ansy = y;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%s",str+1);int len = strlen(str+1);
        FOR(j,1,len){
            if(str[j] == 'B') x[i]++;
            else y[i]++;
        }
    }
    int l = 0,r = 500000+5,ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    printf("%d\n",ans);
    chk(ans);
    FOR(i,1,ansx) putchar('B');
    FOR(i,1,ansy) putchar('N');
    puts("");
    return 0;
}