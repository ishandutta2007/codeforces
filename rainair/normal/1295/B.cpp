/*
 * Author: RainAir
 * Time: 2020-03-05 10:10:42
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

const int MAXN = 1e5 + 5;
char str[MAXN];
int n,x;

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&x);scanf("%s",str+1);
        int p0 = 0,p1 =0,s0=0,s1=0;
        FOR(i,1,n) s0 += (str[i]=='0'),s1 += (str[i] == '1');
        int delta = s0-s1;
        if(s0 == s1){
            bool flag = false;
            FOR(i,1,n){
                p0+=(str[i]=='0');p1 += (str[i] == '1');
                if(p0-p1 == x){
                    flag = true;break;
                }
            }
            puts(flag ? "-1" : "0");continue;
        }int ans = 0;
        FOR(i,1,n){
            p0 += (str[i]=='0');p1 += (str[i]=='1');
            int t1 = p0-p1;
         //   DEBUG(t1);
            if((x-t1)%delta == 0 && (x-t1)/delta >= 0) ans++;
        }
        printf("%d\n",ans+(x==0));
    }
    return 0;
}