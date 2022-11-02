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

const int MAXN = 3e5 + 5;
char str[MAXN];
int n;

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    FOR(i,2,n){
        if(str[i] == str[i-1]){
            FOR(j,0,25){
                if(str[i-1] != 'a'+j && (i==n||str[i+1] != 'a'+j)){str[i] = 'a'+j;break;}
            }
        }
    }
    printf("%s\n",str+1);
    return 0;
}