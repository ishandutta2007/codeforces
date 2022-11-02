#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 4e5 + 5;
int a[MAXN];
int n;
std::vector<int> S;
int m;
P cnt[MAXN];
int sm[MAXN];

bool p[MAXN];
int cc[MAXN],tp;
std::vector<std::vector<int> > ans;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),S.pb(a[i]);
    std::sort(all(S));S.erase(std::unique(all(S)),S.end());
    FOR(i,1,n) a[i] = std::lower_bound(all(S),a[i])-S.begin()+1;
    m = S.size();FOR(i,1,n) cnt[a[i]].fi++;
    FOR(i,1,m) cnt[i].se = S[i-1];
    std::sort(cnt+1,cnt+m+1);
    FOR(i,1,m) sm[i] = sm[i-1]+cnt[i].fi;
    int ansi=0,ansj=0;
    FOR(i,1,n){
        FOR(j,i,n){
            if(1ll*i*j > n) break;
            int t = std::min(i,j);
            int p = std::upper_bound(cnt+1,cnt+m+1,MP(t,1000000000))-cnt-1;
            int s = sm[p]+(m-p)*t;
            if(s >= i*j){
                if(i*j > ansi*ansj){
                    ansi=i;ansj=j;
                }
            }
        }
    }
    printf("%d\n%d %d\n",ansi*ansj,ansi,ansj);
    int kk = std::min(ansi,ansj);
    ROF(i,m,1) FOR(j,1,std::min(cnt[i].fi,kk)) cc[++tp] = cnt[i].se;
    ans.resize(ansi);
    FOR(i,0,ansi-1) ans[i].resize(ansj);
    int ii=-1,jj=-1;
    FOR(i,0,ansi*ansj-1){
        ii++;jj++;ii%=ansi;jj%=ansj;
        while(ans[ii][jj]) jj++,jj%=ansj;
        ans[ii][jj] = cc[i+1];
    }
    FOR(i,0,ansi-1) FOR(j,0,ansj-1) printf("%d%c",ans[i][j]," \n"[j==ansj-1]);
    return 0;
}