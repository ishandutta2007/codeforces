/*
 * Author: RainAir
 * Time: 2020-05-17 17:30:09
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
const int MAXN = 4e5 + 5;
char str[MAXN];
int n;

inline void Solve(){
    scanf("%s",str+1);n = strlen(str+1);
    int mx1=-1,mx2=-1,mx3=-1;int ans = 1e9;
    FOR(i,1,n){
        if(str[i] == '1'){
            mx1 = i;
            if(mx2 != -1 && mx3 != -1) ans = std::min(ans,i-std::min(mx2,mx3)+1);
        }
        else if(str[i] == '2'){
            mx2 = i;
            if(mx1 != -1 && mx3 != -1) ans = std::min(ans,i-std::min(mx1,mx3)+1);
        }
        else{
            mx3 = i;
            if(mx1 != -1 && mx2 != -1) ans = std::min(ans,i-std::min(mx1,mx2)+1);
        }
    }
    printf("%d\n",ans==1e9?0:ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}