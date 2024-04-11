/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-18 15:15:13
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
#define P std::pair<LL,LL>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 2e5 + 5;
std::set<P> seg;
int n,m;
int l[MAXN],r[MAXN];
int L[MAXN],R[MAXN];
P a[MAXN];

struct Seg{
    int l,r,id;

    bool operator < (const Seg &t) const {
        return r > t.r;
    }
}s[MAXN];
int ans[MAXN];
std::priority_queue<Seg> q;

inline bool cmp(const Seg &a,const Seg &b){
    return a.l < b.l;
}

signed main(){
    scanf("%lld%lld",&n,&m);
    FOR(i,1,n) scanf("%lld%lld",l+i,r+i);
    FOR(i,1,m) scanf("%lld",&a[i].fi),a[i].se = i;
    FOR(i,2,n) s[i-1].l = l[i]-r[i-1],s[i-1].r = r[i]-l[i-1],s[i-1].id = i-1;
    std::sort(s+1,s+n,cmp);std::sort(a+1,a+m+1);
    bool flag = true;int now = 1,cnt = 0;
    FOR(i,1,m){
        while(now <= n && s[now].l <= a[i].fi && a[i].fi <= s[now].r){
            q.push(s[now++]);
        }
        if(!q.size()) continue;
        Seg v = q.top();q.pop();
        if(v.r < a[i].fi){
            flag = false;
            break;
        }++cnt;
        ans[v.id] = a[i].se;
    }
    if(cnt != n-1) flag = false;
    if(!flag) puts("No");
    else{
        puts("Yes");
        FOR(i,1,n-1) printf("%lld ",ans[i]);puts("");
    }
    return 0;
}