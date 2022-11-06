#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n, m, q;

vector<int> E[3010];
vector<int> R[3010];

void in(){
	read(n, m, q);
	for(int i=1; i<=m; ++i){
		int a, b; read(a, b);
		E[a].pb(b); R[b].pb(a);
	}
}

void srt(){
	for(int i=1; i<=n; ++i){
		sort(all(E[i]));
	}
}

typedef tuple<int,int,int> t3;

bool vis[3010];
int nxt[20][3010];

char todoku[3010];

vector<t3> query[3010];
int ans[400010];

void iku(){
	for(int t=1; t<=n; ++t){
		memset(todoku, 0, sizeof(todoku));
		queue<int> q;
		q.push(t); todoku[t]=1;
		while(q.size()){
			int x=q.front(); q.pop();
			for(int y:R[x]){
				if(todoku[y]) continue;
				todoku[y]=1;
				q.push(y);
			}
		}
		for(int i=1; i<=n; ++i){
			nxt[0][i]=0;
			for(int j:E[i]) if(todoku[j]){
				nxt[0][i]=j; break;
			}
		}
		nxt[0][t]=t;
		for(int i=1; i<20; ++i){
			for(int j=1; j<=n; ++j) nxt[i][j]=nxt[i-1][nxt[i-1][j]];
		}
		for(auto& T:query[t]){
			int s, k, qi;
			tie(s, k, qi) = T;
			if(nxt[19][s] != t){
				ans[qi] = -1; continue;
			}
			k -= 1;
			auto F = [&](int k){
				int p=s;
				for(int i=0; i<20; ++i)if(1&(k>>i)) p=nxt[i][p];
				return p;
			};
			int qa = F(k);
			if(k && F(k-1) == t){
				ans[qi] = -1;
			} else ans[qi] = qa;
		}
	}
}

int main()
{
	in();
	srt();
	for(int i=1; i<=q; ++i){
		int s, t, k; read(s, t, k);
		query[t].eb(s, k, i);
	}
	iku();
	for(int i=1; i<=q; ++i) printf("%d\n", ans[i]);
	return 0;
}