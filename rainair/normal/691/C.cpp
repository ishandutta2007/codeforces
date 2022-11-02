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
char s[MAXN];int n;

int main(){
    scanf("%s",s+1);n = strlen(s+1);
    int ps = -1;
    FOR(i,1,n) if(s[i] == '.'){ps = i;break;}
    bool flag = 1;
    FOR(i,1,n) flag &= (s[i] == '.' || s[i] == '0');
    if(flag){
        puts("0");
        return 0;
    }
    flag = 1;
    ROF(i,n,ps+1) flag &= (s[i] == '0');
    if(flag) n = ps-1,ps = -1;
    if(ps == -1){
        int l = 1,r = n;
        while(s[l] == '0') ++l;
        while(s[r] == '0') --r;
        putchar(s[l]);
        if(l != r) putchar('.');
        FOR(i,l+1,r) putchar(s[i]);
        if(l != n) printf("E%d",n-l);
        puts("");return 0;
    }
    else{
        bool flag = 1;
        FOR(i,1,ps-1) flag &= (s[i] == '0');
        if(flag){
            int l = ps+1,r = n;
            while(s[l] == '0') ++l;
            while(s[r] == '0') --r;
            putchar(s[l]);
            if(l != r) putchar('.');
            FOR(i,l+1,r) putchar(s[i]);
            printf("E%d\n",-(l-ps));
        }
        else{
            int l = 1,r = n;
            while(s[l] == '0') ++l;
            while(s[r] == '0') --r;
            putchar(s[l]);
            if(r-l >= 2) putchar('.');
            FOR(i,l+1,ps-1) putchar(s[i]);
            FOR(i,ps+1,r) putchar(s[i]);
            if(ps-l > 1) printf("E%d",ps-l-1);
            puts("");
        }
    }
    return 0;
}