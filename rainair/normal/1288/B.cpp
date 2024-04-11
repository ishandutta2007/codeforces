/*
 * Author: RainAir
 * Time: 2020-03-06 10:14:11
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

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int a,b;scanf("%d%d",&a,&b);
        bool flag = 1;int cnt = 0;
        int t = b;while(t) flag &= (t%10==9),t /= 10,++cnt;
        if(!flag) cnt--;
        printf("%lld\n",1ll*cnt*a);
    }
    return 0;
}