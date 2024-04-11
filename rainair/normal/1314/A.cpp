/*
 * Author: RainAir
 * Time: 2020-03-01 20:24:07
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
#define int LL
const int MAXN = 2e5 + 5;
struct Node{
    int a,t;
    bool operator < (const Node &t) const {
        return a < t.a;
    }
}a[MAXN];
int ans = 0;
int n,sm = 0;

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n) scanf("%lld",&a[i].a);
    FOR(i,1,n) scanf("%lld",&a[i].t);
    std::sort(a+1,a+n+1);int now;
    for(int i = 1;i <= n;){
        std::priority_queue<int> q;
        q.push(a[i].t);int now = a[i].a,sm = a[i].t;
        int j = i+1;
        while(233){
            while(j <= n && a[j].a <= now){
                q.push(a[j].t);
                sm += a[j++].t;
            }
            if(q.size() == 1) break;
            sm -= q.top();q.pop();
            ans += sm;now++;
        }
        i = j;
    }
    printf("%lld\n",ans);
    return 0;
}