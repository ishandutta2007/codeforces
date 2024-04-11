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

int v(char c) {
    if(c=='I') return 1;
    if(c=='E') return 1;
    if(c=='A') return 1;
    if(c=='O') return 1;
    if(c=='U') return 1;
    if(c=='Y') return 1;
    return 0;
}

#define MAXN 500010

double pre[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    REP(i,MAXN) if(i) pre[i]=pre[i-1]+1.0/i;
    string s;
    while(cin>>s) {
        int n = s.length();
        ll d = 0;
        double co = 0;
        double ans = 0;
        REP(i,n) {
            co += pre[n-i]-pre[i];
            if(v(s[i])) {
                ans += co;
            }
            //cout<<co<<endl;
        }
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}