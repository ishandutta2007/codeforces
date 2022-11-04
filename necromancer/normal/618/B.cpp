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
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

int a[100][100];
int ans[100];

int main()
{
#ifdef LOCAL
	   //freopen("x.in","r",stdin);
	   //freopen("x.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	REP(i,n)
	REP(j,n)
		cin>>a[i][j];
	REP(i,n) {
		REP(j,n) {
			int ok = 1;
			REP(k,n) {
				if(a[j][k] != i+1 && a[j][k] != 0)
					ok = 0;
				if(a[k][j] != i+1 && a[k][j] != 0)
					ok = 0;
			}
			if(ok) {
				REP(k,n) {
					a[j][k] = a[k][j] = 0;
				}
				a[j][j] = -1;
				ans[j] = i+1;
				break;
			}
		}
	}
	REP(i,n) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}