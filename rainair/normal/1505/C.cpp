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

const int MAXN = 2e5 + 5;
char str[MAXN];
int n;
bool vis[MAXN];
int f[MAXN];

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    FOR(i,3,n){
        int p1 = str[i]-'A',p2 = str[i-1]-'A',p3 = str[i-2]-'A';
        if(p1 != (p2+p3)%26){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}