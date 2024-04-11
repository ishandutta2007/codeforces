/*
 * Author: RainAir
 * Time: 2020-05-27 08:51:06
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
LL a[MAXN],b[MAXN];
int n;
std::vector<char> ans;
LL t1;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lld",a+i);
    FOR(i,1,n) scanf("%lld",b+i);
    if(n == 1){
        if(a[1] == b[1]){
            printf("SMALL\n0\n\n");
            return 0;
        }
        puts("IMPOSSIBLE");
        return 0;
    }
    if(n == 2){
        bool f1 = a[1]>a[2],f2 = b[1] > b[2];
        if(f1) std::swap(a[1],a[2]);if(f2) std::swap(b[1],b[2]);
        while(true){
            if(a[1] == b[1]){
                if((b[2]-a[2])%b[1] == 0){
                    t1 += std::abs(b[2]-a[2])/b[1];
                    if(t1 > 200000){
                        printf("BIG\n%lld\n",t1);
                        return 0;
                    }
                    std::reverse(all(ans));
                    printf("SMALL\n%lld\n",(int)ans.size()+std::abs(b[2]-a[2])/b[1]+f1+f2);
                    if(f1) putchar('R');
                    if(b[2] > a[2]){
                        FOR(i,1,(b[2]-a[2])/b[1]) putchar('P');
                        for(auto x:ans) printf("%c",x);
                    }
                    else{
                        for(auto x:ans) printf("%c",x);
                        FOR(i,1,(a[2]-b[2])/b[1]) putchar('P');
                    }
                    if(f2) putchar('R');puts("");return 0;
                }
                puts("IMPOSSIBLE");
                return 0;
            }
            else if(b[1] == b[2]){
                puts("IMPOSSIBLE");
                return 0;
            }
            else{// b[1] < b[2]
                LL t = b[2]/b[1];
                b[2] -= b[1]*t;
                if(b[2] == 0) t--,b[2] += b[1];
                t1 += t;
                if(t1 <= 200000) FOR(i,1,t) ans.pb('P');
                ans.pb('R');std::swap(b[1],b[2]);
            }
        }
    }
    if(n >= 3){
        while(true){
            bool inc=1,dec = 1;
            FOR(i,2,n) inc &= b[i-1] < b[i],dec &= b[i-1] > b[i];
            bool eq = 1,req = 1;
            FOR(i,1,n) eq &= b[i] == a[i],req &= b[i] == a[n-i+1];
//            FOR(i,1,n) printf("%lld ",b[i]);puts("");
            if(eq){
                break;
            }
            if(req){
                ans.pb('R');
                break;
            }
            if(inc){
                ans.pb('P');t1++;
                ROF(i,n,1) b[i] -= b[i-1];
            }
            else if(dec){
                ans.pb('R');
                std::reverse(b+1,b+n+1);
            }
            else{
                bool eq = 1;
                FOR(i,1,n) eq &= b[i]==a[i];
                if(eq) break;
                std::reverse(b+1,b+n+1);eq = 1;ans.pb('R');
                FOR(i,1,n) eq &= b[i]==a[i];
                if(eq) break;
                puts("IMPOSSIBLE");
                return 0;
            }
        } 
        if(t1 > 200000){
            printf("BIG\n%lld\n",t1);
            return 0;
        }
        puts("SMALL");
        std::reverse(all(ans));
        printf("%d\n",(int)ans.size());
        for(auto x:ans) printf("%c",x);
        puts("");
    }
    return 0;
}