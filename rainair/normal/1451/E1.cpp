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

const int MAXN = 1e5 + 5;
int a[MAXN],n,ans[MAXN];
std::vector<P> S;
int b[MAXN];

int main(){
    int n;scanf("%d",&n);
    FOR(i,2,n){
        printf("XOR %d %d\n",1,i);std::fflush(stdout);
        scanf("%d",a+i);
    }
    FOR(i,1,n) S.pb(MP(a[i],i));std::sort(all(S));
    int ps = -1;
    FOR(i,1,n-1) if(S[i].fi == S[i-1].fi){ps = i;break;}
    if(ps != -1){
        int x = S[ps-1].se,y = S[ps].se;
        printf("AND %d %d\n",x,y);std::fflush(stdout);
        scanf("%d",ans+x);ans[y] = ans[x];
        FOR(i,1,n){
            if(i != x && i != y) ans[i] = ans[x]^a[x]^a[i];
        }
    }
    else{
        FOR(i,1,n) b[a[i]] = i;
        int x = 1,y = b[a[x]^(n-1)],z = 2;
        if(z == y) ++z;
        int xay = 0,xaz = 0,yaz = 0;
        printf("AND %d %d\n",x,z);std::fflush(stdout);scanf("%d",&xaz);
        printf("AND %d %d\n",y,z);std::fflush(stdout);scanf("%d",&yaz);
        int xy = (a[x]^a[y])+2*xay,xz = (a[x]^a[z])+2*xaz,yz = (a[y]^a[z])+2*yaz;
        ans[y] = (xy-xz+yz)>>1;
        ans[x] = xy-ans[y];
        ans[z] = yz-ans[y];
        FOR(i,1,n){
            if(i != x && i != y && i != z) ans[i] = a[i]^a[x]^ans[x];
        }
    }
    printf("! ");FOR(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);std::fflush(stdout);
    return 0;
}