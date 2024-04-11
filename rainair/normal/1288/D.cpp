/*
 * Author: RainAir
 * Time: 2020-03-06 10:31:34
 */
#include<bits/stdc++.h>

#define fi first
#define se second
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

const int MAXN = 3e5 + 5;
const int MAXM = 8;
int a[MAXN][MAXM];
int c[MAXN];
int n,m;
int tag[(1<<MAXM)+3];
int ansx,ansy;

inline bool chk(int k){
    CLR(tag,0);
    FOR(i,1,n){
        c[i] = 0;
        FOR(j,0,m-1){
            if(a[i][j] >= k) c[i] |=(1<<j);
        }
        for(int S=c[i];S;S=(S-1)&c[i]){
            tag[S]=i;
        }
        tag[0] = i;
        if(tag[((1<<m)-1)^c[i]]){
            ansx = tag[((1<<m)-1)^c[i]];
            ansy = i;
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) FOR(j,0,m-1) scanf("%d",&a[i][j]);
    int l = 0,r = 1e9,ans = -1,ansx=-1,ansy=-1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)){
            ans = mid,l = mid+1;
            ansx = ::ansx;ansy=::ansy;
        }
        else r = mid-1;
    }
    //DEBUG(ans);
    printf("%d %d\n",ansx,ansy);
    return 0;
}
/*
 *  k
 *   b >=k
 *   a >=k   or  1
 *   
 */