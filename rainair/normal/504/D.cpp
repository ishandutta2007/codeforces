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

const int MAXN = 2000;
int n;
char str[MAXN+5];int t[MAXN+5];
std::bitset<MAXN+5> x,y;
std::bitset<MAXN+5> b[MAXN+5],sol[MAXN+5];

inline void trans(){
    scanf("%s",str+1);int len = strlen(str+1);
    std::reverse(str+1,str+len+1);int k = 0;
    FOR(i,1,len){
        int l = (i-1)*8+1,r = std::min(i*8,len);
        if(l > len) break;++k;
        ROF(j,r,l) t[k] = t[k]*10+str[j]-'0';
    }
    int m = 0;x.reset();len = k;
//    DEBUG(len);DEBUG(t[1]);
    while(len){
        LL r = 0;
        ROF(i,len,1){
            r = r*100000000+t[i];
            t[i] = r>>32;
            r %= (1ll<<32);
        }
        FOR(i,0,31) x[m++] = ((r>>i)&1);
        while(len && !t[len]) --len;
    }
}

int main(){
//    freopen("A.in","r",stdin);
    //freopen("A.ans","w",stdout);
    scanf("%d",&n);
    FOR(cc,0,n-1){
        trans();y.reset();y[cc] = 1;
//        ROF(i,30,0) putchar(x[i]+'0');puts("");
        bool flag = 0;
        ROF(i,2000,0){
            if(x[i]){
                if(b[i][i]){
                    x ^= b[i];y ^= sol[i];
                }
                else{
                    b[i] = x;sol[i] = y;flag = 1;break;
                }
            }
        }
        if(flag) puts("0");
        else{
            printf("%d ",(int)y.count()-1);
            FOR(i,0,cc-1) if(y[i]) printf("%d ",i);
            puts("");
        }
    }
    return 0;
}