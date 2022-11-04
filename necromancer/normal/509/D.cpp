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

#define MOD 1000000007

int a[100][100];

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m) {
        int mx = 0;
        ll mod = 0;
        REP(i,n) {
            map<ll,int> mp;
            REP(j,m) {
                cin>>a[i][j];
                mx = max(mx, a[i][j]);
                if(i) mp[a[i][j]-a[0][j]]++;
            }
            if(i) {
                ll l = LLONG_MAX;
                if(mp.size()>2) mod = -1;
                for(auto it = mp.begin(); it != mp.end(); it++) {
                    if(l != LLONG_MAX) {
                        if(mod == (it->X)-l || mod == 0) mod = (it->X)-l;
                        else mod = -1;
                    }
                    l = it->X;
                }
            }
        }
        if(mod == 0) mod = MOD;
        if(mod <= mx) {cout<<"NO"<<endl; continue;}
        cout<<"YES"<<endl;
        cout<<mod<<endl;
        REP(i,n) cout<<((a[i][0]-a[0][0])%mod+mod)%mod<<' ';
        cout<<endl;
        REP(i,m) cout<<a[0][i]<<' ';
        cout<<endl;
    }
    return 0;
}