/*
 * Author: RainAir
 * Time: 2020-03-02 10:03:06
 */
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
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5000+5;
const int ha = 1e9 + 7;

int n,m;
int s[MAXN];
std::vector<int> G[MAXN],l[MAXN],r[MAXN];
int pre[MAXN][MAXN],suf[MAXN][MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",s+i);
    FOR(i,1,m){
        int x,y;scanf("%d%d",&x,&y);
        G[x].pb(y);
    }
    FOR(i,1,n){
        if(G[i].empty()) continue;
        std::sort(all(G[i]));
        int cnt = 0,now = 0;
        FOR(j,1,n){
            if(s[j] == i){
                cnt++;
                if(cnt == G[i][now]){
                    l[i].pb(j);
                    now++;
                    if(now == (int)G[i].size()) break;
                }
            }
        }
        cnt = now = 0;
        ROF(j,n,1){
            if(s[j] == i){
                cnt++;
                if(cnt == G[i][now]){
                    r[i].pb(j);now++;
                    if(now == (int)G[i].size()) break;
                }
            }
        }
        while(l[i].size() != G[i].size()) l[i].pb(233333);
        while(r[i].size() != G[i].size()) r[i].pb(-666666);
    }
    int ans1 = 0,ans2 = 1;
    G[0].pb(0);l[0].pb(0);r[0].pb(0);
    FOR(x,0,n+1){
        for(auto mid:l[x]){ // 
            if(mid == 233333) continue;
            int now1 = 0,now2 = 1;
            FOR(i,1,n){
                if(G[i].empty()) continue;
                int a = 0,b = 0,c = 0;// ->  <- 
                FOR(j,0,(int)G[i].size()-1){
                    if(l[i][j] < mid && r[i][j] > mid) ++c;
                    else if(l[i][j] <= mid) ++a;
                    else if(r[i][j] > mid) ++b;
                }
                if(i && i == x){
                    b += c;a = c = 0;
                }
                if(a*b+a*c+b*c+c*(c-1)>0){
                    now1 += 2;
                    int t = 1ll*a*b%ha;
                    (t += 1ll*a*c%ha)%=ha;
                    (t += 1ll*b*c%ha)%=ha;
                    (t+=1ll*c*(c-1)%ha)%=ha;
                    now2 = 1ll*now2*t%ha;
                }
                else if(a+b+c*2){
                    now1++;
                    now2 = 1ll*now2*(a+b+c*2ll%ha)%ha;
                }
            }
            if(x) now1++;
            if(ans1 < now1){
                ans1 = now1;ans2 = now2;
            }
            else if(ans1 == now1){
                (ans2 += now2)%=ha;
            }
        }
    }
    printf("%d %d\n",ans1,!ans1?1:ans2);
    return 0;
}