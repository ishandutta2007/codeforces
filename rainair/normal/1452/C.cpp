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

const int MAXN = 2e5 + 5;
char str[MAXN];int n;

inline void Solve(){
    scanf("%s",str+1);n = strlen(str+1);
    int t1 = 0,t2 = 0,ans = 0;
    FOR(i,1,n){
        if(str[i] == '[') ++t1;
        else if(str[i] == '(') ++t2;
        else if(str[i] == ']') {if(t1) --t1,++ans;}
        else if(t2) --t2,++ans;
    }
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}