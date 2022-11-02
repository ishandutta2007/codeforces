#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int u,v;scanf("%d%d",&u,&v);
        if(u > v){
            puts("NO");
            continue;
        }
        if(u%2 == 0 && v%2 == 1){
            puts("NO");
            continue;
        }
        std::queue<int> s,t;
        FOR(i,0,30){
            if(u&1) s.push(i);
            u >>= 1;
            if(v&1) t.push(i);
            v >>= 1;
        }
        bool flag = 1;
        while(!t.empty()){
            while(!s.empty() && s.front() > t.front()) s.pop();
            if(s.empty()){
                flag = 0;
                break;
            }
            s.pop();t.pop();
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}