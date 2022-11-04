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

int fa[200010];
int val[200010];

ll dp[200010];
ll dp1[200010];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    REP2(i,1,n) {
        cin>>fa[i]>>val[i];
        if(fa[i]==-1) fa[i]=0;
    }
    CLR(dp,0);
    for(int i = 0; i < 200010; i++) dp1[i] = LLONG_MIN;
    DEP(i,n,1) {
        dp1[i]=max(dp1[i], dp[i]+val[i]);
        ll x=max(dp1[fa[i]]+dp[i], dp[fa[i]]+dp1[i]);
        ll y=max(dp[fa[i]]+dp[i], dp1[fa[i]]+dp1[i]);
        dp1[fa[i]]=x;
        dp[fa[i]]=y;
        //cout<<i<<' '<<dp1[i]<<' '<<dp[i]<<endl;
    }
    cout<<max(dp[0], dp1[0]);
    return 0;
}