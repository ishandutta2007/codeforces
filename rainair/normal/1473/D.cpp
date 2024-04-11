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
int sm[MAXN];
int pmx[MAXN],pmn[MAXN],smx[MAXN],smn[MAXN];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        int n,m;scanf("%d%d",&n,&m);
        scanf("%s",str+1);
        FOR(i,1,n) sm[i] = sm[i-1]+(str[i]=='+'?1:-1);
        pmx[0] = 0;pmn[0] = 0;
        FOR(i,1,n) pmx[i] = std::max(pmx[i-1],sm[i]),pmn[i] = std::min(pmn[i-1],sm[i]);
        std::set<int> S;int tag = 0,t = 0;
        ROF(i,n,1){
            S.insert(-tag);
            tag += (str[i]=='+'?1:-1);
            smn[i] = *S.begin()+tag;
            smx[i] = *S.rbegin()+tag;
        }
        FOR(i,1,m){
            int l,r;scanf("%d%d",&l,&r);
            if(l == 1 && r == n){
                puts("1");
                continue;
            }
            if(r == n){
                printf("%d\n",pmx[l-1]-pmn[l-1]+1);
                continue;
            }
            int l1 = pmn[l-1],r1 = pmx[l-1];
            int l2 = sm[l-1]+smn[r+1],r2 = sm[l-1]+smx[r+1];
            int len = std::max(0,std::min(r1,r2)-std::max(l1,l2)+1);
            printf("%d\n",r1-l1+1+r2-l2+1-len);
        }
    }
    return 0;
}