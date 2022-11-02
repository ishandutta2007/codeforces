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

const int MAXN = 1e6 + 5;

char s[MAXN],t[MAXN];int n;

inline void inc(char s[]){
    ROF(i,n,1){
        if(s[i] == '1'){s[i] = '0';continue;}
        s[i] = '1';return;
    }
}

int main(){
    scanf("%d%s%s",&n,s+1,t+1);
    if(n == 1){
        if(s[1] == '0' && t[1] == '0') puts("0");
        else puts("1");
        return 0;
    }
    if(s[1]^t[1]){
        FOR(i,1,n) putchar('1');puts("");
        return 0;
    }
    bool flag = 1;FOR(i,1,n) flag &= (t[i] == '1');
    if(flag){
        FOR(i,1,n) putchar(t[i]);puts("");
        return 0;
    }
    FOR(i,1,4){
        if(t[n] == '0' && t[n-1] == '0' && s[n] == '0' && s[n-1] == '1'){
            t[n] = '1';
            FOR(i,1,n) putchar(t[i]);puts("");
            return 0;
        }
        if(t[n] == '0' && t[n-1] == '1' && s[n] == '0' && s[n-1] == '0'){
            t[n] = '1';
            FOR(i,1,n) putchar(t[i]);puts("");
            return 0;
        }
        bool flag = 1;
        FOR(j,1,n) flag &= (s[j] == t[j]);
        if(flag) break;
        inc(s);
    }
    FOR(i,1,n) putchar(t[i]);puts("");
    return 0;
}