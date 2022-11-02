#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
const int MAXN = 5e5 + 5;
char str[MAXN];
char a[MAXN],b[MAXN];
int t1=0,t2=0;
int n;

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    for(int l = 0,r;l <= n;l = r+1){
        r = l;while(r+1 <= n && str[r+1] != ',' && str[r+1] != ';') ++r;
        if(l == r){
            b[++t2] = ',';
            continue;
        }
        bool flag = 1;
        FOR(i,l+1,r){
            flag &= isdigit(str[i]);
        }
        if(r-l > 1) flag &= (str[l+1] != '0');
        if(flag){
            FOR(i,l+1,r) a[++t1] = str[i];
            a[++t1] = ',';
        }
        else{
            FOR(i,l+1,r) b[++t2] = str[i];
            b[++t2] = ',';
        }
    }
    if(t1){
        putchar('\"');
        FOR(i,1,t1-1) putchar(a[i]);puts("\"");
    }
    else{
        puts("-");
    }
    if(t2){
        putchar('\"');
        FOR(i,1,t2-1) putchar(b[i]);puts("\"");
    }
    else{
        puts("-");
    }
    return 0;
}