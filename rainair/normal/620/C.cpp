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
int n;
std::map<int,int> S;

int main(){
    scanf("%d",&n);
    std::vector<P<int,int> > ans;
    int las = 1;
    FOR(i,1,n){
        int x;scanf("%d",&x);
        S[x]++;
        if(S[x] == 2){
            S.clear();
            ans.pb(MP(las,i));
            las = i+1;
        }
    }
    if(ans.empty()){
        puts("-1");
        return 0;
    }
    if(las != n+1) ans.back().se = n;
    printf("%d\n",SZ(ans));
    for(auto x:ans) printf("%d %d\n",x.fi,x.se);
    return 0;
}