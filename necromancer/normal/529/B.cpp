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

int x[1000];
int y[1000];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    REP(i,n) {
        cin>>x[i]>>y[i];
    }
    int ans = INF;
    REP2(h,1,1000) {
        int k = n/2;
        int W = 0;
        VI v;
        REP(i,n) {
            if(y[i]<=h) {
                if(x[i]<=h) {
                    v.PB(y[i]-x[i]);
                    W+=x[i];
                }else{
                    W+=x[i];
                }
            }else{
                if(x[i]>h) k=-1;
                W+=y[i];
                k--;
            }
        }
        sort(v.begin(),v.end());
        REP(i,v.size()) {
            if(k>0 && v[i]<0) {
                W+=v[i];
                k--;
            }
        }
        if(k>=0) ans = min(ans, W*h);
    }
    cout<<ans<<endl;
    return 0;
}