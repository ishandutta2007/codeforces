#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)
#define MAXN 500000
int vis[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    ll h,w,n;
    char s[2];
    ll x;
    scanf("%I64d%I64d%I64d",&w,&h,&n);
    map<ll,ll> m1,m2;
    PQ<PII> Q1,Q2;
    m1.insert(MP(0,0));
    m1.insert(MP(h,MAXN-1));
    m2.insert(MP(0,1));
    m2.insert(MP(w,MAXN-1));
    
    Q1.push(MP(h,0));
    Q2.push(MP(w,1));
    int p=2;
    REP(i,n) {
        scanf("%s%I64d",s,&x);
        if(s[0]=='H') {
            auto it = m1.lower_bound(x);
            auto it2=it--;
            if(it->X != x) {
                vis[it->Y]=1;
                it->Y=p;
                Q1.push(MP(x-it->X, p++));
                m1.insert(MP(x,p));
                Q1.push(MP(it2->X-x, p++));
            }
        }else{
            auto it = m2.lower_bound(x);
            auto it2=it--;
            if(it->X != x) {
                vis[it->Y]=1;
                it->Y=p;
                Q2.push(MP(x-it->X, p++));
                m2.insert(MP(x,p));
                Q2.push(MP(it2->X-x, p++));
            }
        }
        while(vis[Q1.top().Y]) Q1.pop();
        while(vis[Q2.top().Y]) Q2.pop();
        printf("%I64d\n",Q1.top().X*Q2.top().X);
    }
    return 0;
}