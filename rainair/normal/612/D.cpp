#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
int k,n;
std::vector<P<int,int> > S;

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n){
        int l,r;scanf("%d%d",&l,&r);
        S.pb(MP(l,1));S.pb(MP(r,-1));
    }
    std::sort(all(S));
    int now = 0;int lst = -1e9;
    std::vector<P<int,int> > ans;
    for(int l = 0,r;l < S.size();l = r+1){
        int pre = now;
        int c1=0,c2=0;
        r = l;
        S[r].se > 0?++c1:++c2;
        while(r+1 < S.size() && S[r+1].fi == S[l].fi){
            ++r;
            S[r].se > 0 ? ++c1:++c2;
        }
        now += c1;
        if(pre < k && now >= k){
            lst = S[l].fi;
        }
        pre = now;
        now -= c2;
        if(pre >= k && now < k){
            ans.pb(MP(lst,S[l].fi));
            pre = -1e9;
        }
//        now -= c2;
    }
    printf("%d\n",SZ(ans));
    for(auto x:ans) printf("%d %d\n",x.fi,x.se);
    return 0;
}