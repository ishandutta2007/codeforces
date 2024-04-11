/*
 * Author: RainAir
 * Time: 2020-03-05 10:06:38
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
        int n;scanf("%d",&n);
        std::vector<int> ans;
        ans = std::vector<int>(n/2,1);
        n %= 2;
        if(n == 1) ans[0] = 7;
        for(auto x:ans) printf("%d",x);puts("");
    }
    return 0;
}