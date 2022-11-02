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
int a[MAXN],n;
std::set<P<int,int> > S;int tag;
int val[MAXN];

int main(){
    scanf("%d",&n);
    if(n == 1){
        puts("1");
        return 0;
    }
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) val[i] = 1e9,S.insert(MP(val[i],i));
    a[0] = 0;
    S.insert(MP(0,0));
    FOR(i,0,n-1){
        auto p = S.begin();
        int mn = 1e9;
        if(p->se == a[i+1]){
            mn = std::min(mn,p->fi);
        }
        else{
            mn = std::min(mn,p->fi+1);
            mn = std::min(mn,val[a[i+1]]);
        }
        mn = std::min(mn,val[a[i]]+(a[i] != a[i+1]));
        S.erase(MP(val[a[i]],a[i]));
        val[a[i]] = mn-(a[i] != a[i+1]);
        S.insert(MP(val[a[i]],a[i]));
        tag += a[i] != a[i+1];
//        FOR(i,0,3) printf("%d ",val[i]+tag);puts("");
    }
    printf("%d\n",tag+S.begin()->fi);
    return 0;
}