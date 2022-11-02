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

const int MAXN = 1e5 + 5;
int a[MAXN],n;
std::vector<int> v[MAXN];
int q[MAXN],c[MAXN];
// q: [1,i]  c 

inline bool pd(int l,int r){
    for(auto x:v[r]) if(x == r-l+1) return 1;
    return 0;
}

int main(){
    scanf("%d",&n);int now = 0;
    q[0] = 1;int xyx = 0;
    FOR(ccc,1,n){
        ++now;scanf("%d",a+now);v[now].clear();
        if(now != 1){
            if(a[now] == a[now-1]) v[now].pb(2);
            for(auto x:v[now-1]) if(a[now-x-1] == a[now]) v[now].pb(x+2);
        }
        if(!v[now].empty() && pd(now-v[now][0]/2-v[now][0]+1,now-v[now][0]/2)){
            now -= v[now][0];
            xyx += 2;
        }
        else{
            q[now] = q[now-1];c[now] = c[now-1];
            if(pd(q[now],now)){
                q[now] += (now-q[now]+1)/2;
                c[now]++;
            }
        }
        int ans = xyx+c[now],p = now;
        while(!v[p].empty() && p-v[p][0]/2 >= q[now]){
            p -= v[p][0]/2;
            ans++;
        }
        printf("%d ",ans);
    }
    puts("");
    return 0;
}