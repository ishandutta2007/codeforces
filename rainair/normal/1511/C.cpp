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
const int M = 50;
int n,q;
int fi[M+20];
std::vector<P<int,int> > S;

int main(){
    scanf("%d%d",&n,&q);
    FOR(i,1,n){
        int x;scanf("%d",&x);
        if(!fi[x]) fi[x] = i;
    }
    FOR(i,1,M) if(fi[i]) S.pb(fi[i],i);
    std::sort(all(S));
    while(q--){
        int x;scanf("%d",&x);
        int ps = -1;
        FOR(i,0,SZ(S)-1){
            if(S[i].se == x){
                ps = i;break;
            }
        }
        printf("%d ",S[ps].fi);
        P<int,int> tmp = S[ps];
        S.erase(S.begin()+ps);
        S.insert(S.begin(),tmp);
        FOR(i,1,ps) S[i].fi++;
        S[0].fi = 1;
    }
    puts("");
    return 0;
}