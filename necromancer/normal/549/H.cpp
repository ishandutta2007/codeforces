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

double gao(double a, double x) {
    if(a > 0) a -= x;
    else a += x;
    return a;
}

bool duang(double a, double b, double c, double d, double M) {
    double mx = max((a+M) * (d+M), (a-M) * (d-M));
    double mn = fabs(M) >= min(fabs(a), fabs(d)) ? 0 : gao(a, M) * gao(d, M);
    double mx2 = max((b+M) * (c+M), (b-M) * (c-M));
    double mn2 = fabs(M) >= min(fabs(b), fabs(c)) ? 0 : gao(b, M) * gao(c, M);
    
    double l = max(mn, mn2);
    double r = min(mx, mx2);
    return l<=r;    
}

int main()
{
    ios::sync_with_stdio(false);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    double L = 0., R = 1e9+1;
    REP(i,200) {
        double M = (L+R)/2;
        int r = duang(a,b,c,d,M) || duang(-a,-b,c,d,M);
        if(r) {
            R = M;
        }else{
            L = M;
        }
        
    }
    cout<<fixed<<setprecision(10)<<L<<endl;
    return 0;
}