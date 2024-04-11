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
char str[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        scanf("%s",str+1);
        int ans = 0;
        FOR(i,2,n) if(str[i] == str[i-1]) ans++;
        ans = (ans+1)>>1;
        printf("%d\n",ans);
    }
    return 0;
}