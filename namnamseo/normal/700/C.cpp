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

int n, m;
int F, T;

int ps[30010];
int ec[30010];
vector<int> ei[1010];

bool v1[1010];
int p1[1010];

int ans = 2.1e9;

int p2[1010];
int ind[1010], lowl[1010], nt;
int ig1;
void dfs(int x, int ig2){
	ind[x]=lowl[x]=++nt;
	for(int ii:ei[x]){
		if(ii == ig1 || ii == ig2) continue;
		int y=ps[ii]-x;
		if(ind[y]){
			lowl[x]=min(lowl[x], ind[y]);
		} else {
			p2[y]=ii;
			dfs(y, ii);
			lowl[x]=min(lowl[x], lowl[y]);
		}
	}
}
vector<int> alst;
void Do(int ignore){
	fill(p2+1, p2+n+1, 0);
	fill(ind+1, ind+n+1, 0); nt = 0;
	ig1 = ignore;
	dfs(F, -1);
	if(!p2[T]){
		if(ans > ec[ignore]){
			alst = {ignore};
			ans = ec[ignore];
		}
		return;
	}
	//printf("\nIgnore %d(cost %d)?\n", ignore, ec[ignore]);
	for(int p=T; p!=F;){
		int ii=p2[p];
		int q=ps[ii]-p;
		if(ind[p] == lowl[p]){
			//printf("Edge %d(%d-%d, cost %d) is bridge\n", ii, p, q, ec[ii]);
			if(ans > ec[ignore] + ec[ii]){
				ans = ec[ignore] + ec[ii];
				alst = {ignore, ii};
			}
		}
		p=q;
	}
}

int main()
{
	read(n, m); read(F, T);
	for(int i=1; i<=m; ++i){
		int a, b, c; read(a, b, c);
		ps[i]=a+b; ec[i]=c;
		ei[a].pb(i); ei[b].pb(i);
	}
	{
		queue<int> q;
		q.push(F); v1[F]=1;
		while(q.size()){
			int x=q.front(); q.pop();
			for(int ii:ei[x]){
				int y=ps[ii]-x;
				if(!v1[y]){ v1[y]=1; p1[y]=ii; q.push(y); }
			}
		}
	}
	if(!v1[T]){ puts("0\n0"); return 0; }
	for(int p=T; p!=F; p=ps[p1[p]]-p){
		Do(p1[p]);
	}
	if(ans == int(2.1e9)){
		puts("-1"); return 0;
	}
	printf("%d\n", ans);
	printf("%llu\n", alst.size());
	for(int x:alst) printf("%d ", x);
	return 0;
}