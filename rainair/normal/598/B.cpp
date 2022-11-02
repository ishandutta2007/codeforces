#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 10000+5;
char str[MAXN];
int n,m;

int main(){
    scanf("%s",str+1);n = strlen(str+1);
    scanf("%d",&m);
    FOR(cc,1,m){
        int l,r,k;scanf("%d%d%d",&l,&r,&k);k %= (r-l+1);
        if(k){
            std::vector<char> v1,v2;
            int p = r-k+1;
            FOR(i,l,p-1) v1.pb(str[i]);
            FOR(i,p,r) v2.pb(str[i]);
            int t = l-1;
            for(auto x:v2) str[++t] = x;
            for(auto x:v1) str[++t] = x;
        }
    }
    FOR(i,1,n) putchar(str[i]);puts("");
    return 0;
}