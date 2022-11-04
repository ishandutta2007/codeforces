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

string str;

int t[1000000];
ll s[1000010];
int main()
{
    ios::sync_with_stdio(false);
    int n,a,b,T;
    cin>>n>>a>>b>>T;
    cin>>str;
    T += a;
    REP(i,n) t[i] = a + (str[i] == 'w'?b:0);
    REP(i,n) t[i+n] = t[i];
    REP(i,n*2) s[i+1] = s[i] + t[i] + 1;
    int L = 0, R = n;
    int ans = 0;
    while(L <= R) {
        int M = (L+R)>>1;
        int f = 0;
        REP(i,M) {
            ll ss = s[i+n+1] - s[i+n+1-M];
            int mn = min(i, M-i-1);
            if(1LL * mn * a + ss <= T) f = 1;
        }
        if(f) {
            ans = max(ans, M);
            L = M+1;
        }else{
            R = M-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}