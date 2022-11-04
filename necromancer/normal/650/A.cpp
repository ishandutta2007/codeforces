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
typedef pair<int,int> PII;
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

PII p[200000];
map<int, int> mp1, mp2;
map<PII, int> mp;

int main()
{
    int n;
    scanf("%d",&n);
    REP(i,n) {
        scanf("%d%d",&p[i].X,&p[i].Y);
    }
    ll ans = 0;
    REP(i,n) {
        mp1[p[i].X]++;
        mp2[p[i].Y]++;
        mp[p[i]]++;
    }
    for(auto &x : mp1) {
        ans += 1LL*x.Y*(x.Y-1)/2;
    }
    for(auto &x : mp2) {
        ans += 1LL*x.Y*(x.Y-1)/2;
    }
    for(auto &x : mp) {
        ans -= 1LL*x.Y*(x.Y-1)/2;
    }
    printf("%I64d\n", ans);
    return 0;
}