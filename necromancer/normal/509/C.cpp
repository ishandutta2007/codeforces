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

int v0[1000];
int v[1000];

int main()
{
    ios::sync_with_stdio(false);
    int n,x;
    cin>>n;
    v0[0]=0;
    int l0=1;
    REP(i,n) {
        cin>>x;
        int l = max((x+8)/9, l0)+1;
        DEP(i,l-1,0) {
            int s=x;
            REP(j,i) {
                v[l-j-1]=v0[l-j-1];
                s-=v[l-j-1];
            }
            if(s<=v0[l-i-1] || v0[l-i-1]==9) continue;
            if(s>9*(l-i)) continue;
            int d=max(s-9*(l-i-1), v0[l-i-1]+1);
            //if(d>s) continue;
            v[l-i-1]=d;
            s-=d;
            REP(j,l-i-1) {
                int d=min(s,9);
                s-=d;
                v[j]=d;
            }
            break;
        }
        if(v[l-1]==0) l--;
        l0=l;
        REP(i,l) cout<<v[l-i-1];
        cout<<endl;
        memcpy(v0,v,sizeof(v));
    }
    return 0;
}