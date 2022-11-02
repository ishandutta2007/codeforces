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

const int MAXN = 1000+5;
int a[MAXN],n;
bool vis[MAXN];
std::vector<int> S;
inline void Solve(){
    scanf("%d",&n);FOR(i,0,n-1) scanf("%d",a+i);S.clear();
    while(233){
        bool flag = 1;
        FOR(i,0,n-1) flag &= (a[i]==i);
        if(flag) break;
        FOR(i,0,n) vis[i] = 0;
        FOR(i,0,n-1) vis[a[i]] = 1;
        int mex = 0;
        while(vis[mex]) mex++;
        if(mex == n){
            int ps = -1;
            FOR(i,0,n-1){
                if(a[i] != i) {ps = i;break;}
            }
            S.pb(ps);a[ps] = mex;
        }
        else{
            S.pb(mex);a[mex] = mex;
        }
    }
    printf("%d\n",(int)S.size());
    for(auto x:S) printf("%d ",x+1);puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}