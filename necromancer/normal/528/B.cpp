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

#define MAXN 200000
int x[MAXN], w[MAXN], ans[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    VII v;
    PQ<PII, VII, greater<PII> > q;
    REP(i,n) {
        scanf("%d%d",&x[i],&w[i]);
        v.PB(MP(x[i]-w[i],i));
    }
    sort(v.begin(),v.end());
    int mx = 0;
    int res = 0;
    REP(d,v.size()) {
        int i = v[d].Y;
        while(!q.empty() && x[i]-w[i] >= q.top().X) {
            mx = max(mx, q.top().Y);
            q.pop();
        }
        ans[i] = mx+1;
        q.push(MP(x[i]+w[i],ans[i]));
        res = max(res, ans[i]);
    }
    printf("%d\n",res);
    return 0;
}