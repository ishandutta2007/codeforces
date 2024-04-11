#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

const int MAXN = 100+5;
char b[MAXN] = "abacaba";
char str[MAXN];int n;
char tt[MAXN];

inline int get(){
    int res = 0;
    FOR(l,1,n){
        int r = l+7-1;
        if(r > n) break;
        bool f = 1;int t = 0;
        FOR(i,l,r){
            if(tt[i] != b[t]){f = 0;break;}
            t++;
        }
        res += f;
    }
    return res;
}

inline void Solve(){
    scanf("%d%s",&n,str+1);CLR(tt,0);
    FOR(i,1,n) tt[i] = str[i]=='?'?'z':str[i];
    int ttt = get();
    if(ttt == 1){
        puts("Yes");
        printf("%s\n",tt+1);
        return;
    }
    if(ttt > 1){
        puts("No");
        return;
    }
    FOR(l,1,n){
        int r = l+7-1;
        if(r > n) break;
        bool f = 1;int t = 0;
        FOR(i,l,r){
            if(str[i] != b[t] && str[i] != '?'){f = 0;break;}
            t++;
        }
        if(!f) continue;t = 0;
        FOR(i,1,n) tt[i] = str[i];
        FOR(i,l,r) tt[i] = b[t],t++;
        FOR(i,1,n) if(tt[i] == '?') tt[i] = 'z';
        int ttt = get();
        if(ttt == 1){
            puts("Yes");printf("%s\n",tt+1);
            return;
        }
    }
    puts("No");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}