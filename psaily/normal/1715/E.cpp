#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--) 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int mod=998244353;
const ll inf=1ll<<60;
// head
const int N=2e5+5;

int n,q,m,k;
int a[N];
vector<PII> e[N];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,m) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
        u--,v--;
		e[u].pb({v,w});
		e[v].pb({u,w});
	}

    vector<ll> dis(n,inf);
    dis[0]=0;

	auto shortpath=[&]() {
		priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>> > q;
		rep(i,0,n) q.push({dis[i],i});

		while (!q.empty()) {
			auto [d,u]=q.top();	
			q.pop();

            if (d>dis[u]) continue;

			for (auto [v,w]:e[u]) {
				if (dis[v]>dis[u]+w) {
					dis[v]=dis[u]+w;
                    q.push({dis[v],v});
				}
			}
		}
	};

	shortpath();

    // rep(i,0,n) cout << dis[i] << " \n"[i==n-1];
    
    /*
        dp[i][j]=dp[i-1][k]+cost(k,j)
    */

	rep(i,0,k) {
        vector<ll> f(n,inf);
        
        function<void(int,int,int,int)> solve=[&](int l,int r,int L,int R) {
            if (l>r) return;
            int md=(l+r)>>1;
            int best=0;

            rep(i,L,R+1) {
                if (f[md]>dis[i]+1ll*(i-md)*(i-md)) {
                    f[md]=dis[i]+1ll*(i-md)*(i-md);
                    best=i;
                }
            }    
            
            solve(l,md-1,L,best);
            solve(md+1,r,best,R);
        };
        
        solve(0,n-1,0,n-1);
        swap(f,dis);
        shortpath();
	}

    rep(i,0,n) {
        cout << dis[i] << " \n"[i==n-1];
    }

	return 0;
}