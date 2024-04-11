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

const int MAXN = 3e5 + 5;
int s[MAXN],t[MAXN];int n;
char str[MAXN];

inline bool pd(){
    FOR(i,1,n){
        if(s[i] < t[i]) return 1;
        if(s[i] > t[i]) return 0;
    }
    return 0;
}

int main(){
    int L;scanf("%d",&L);
    scanf("%s",str+1);n = strlen(str+1);FOR(i,1,n) s[i] = str[i]-'0';
    bool flag = 1;FOR(i,1,n) flag &= (s[i]==9);
    if((n%L) || flag){
        int now = 0;
        while(now <= n){
            putchar('1');
            FOR(i,1,L-1) putchar('0');
            now += L;
        }
        puts("");
        return 0;
    }
    FOR(i,1,L) t[i] = s[i];
    FOR(i,L+1,n) t[i] = t[i-L];
    if(pd()){
        FOR(i,1,n) putchar('0'+t[i]);
        puts("");
        return 0;
    }
    ++t[L];
    ROF(i,L,2){
        t[i-1] += t[i]/10;
        t[i] %= 10;
    }
    FOR(i,L+1,n) t[i] = t[i-L];
    assert(pd());
    FOR(i,1,n) putchar('0'+t[i]);
    puts("");
    return 0;
}