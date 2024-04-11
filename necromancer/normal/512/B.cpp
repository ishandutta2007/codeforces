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

map<int,int> mp;

void gao(int i, int x) {
    if(mp.count(i)) {
        mp[i] = min(mp[i], x);
    }else{
        mp[i] = x;
    }
}
int l[300], c[300];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    REP(i,n) cin>>l[i];
    REP(i,n) cin>>c[i];
    REP(i,n) {
        VII v;
        v.PB(MP(l[i],c[i]));
        for(auto it = mp.begin(); it!=mp.end(); it++) {
            v.PB(MP(__gcd(l[i], it->X), c[i]+it->Y));
        }
        REP(i,v.size()) {
            gao(v[i].X,v[i].Y);
        }
    }
    int ans = mp[1];
    if(ans == 0) ans = -1;
    cout<<ans<<endl;
    return 0;
}