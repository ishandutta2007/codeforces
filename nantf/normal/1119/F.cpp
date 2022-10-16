#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555;
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
int n,deg[maxn],cur,vis[maxn];
ll f[maxn],g[maxn],sum[maxn];
vector<PII> e[maxn];
inline void add(int u,int v,int w){
	e[u].PB(MP(v,w));
}
inline bool cmp(PII x,PII y){
	return deg[x.first]>deg[y.first];
}
struct wtf_heap{
	multiset<ll> s1,s2;
	int k;
	vector<ll> t1,t2;
	ll sum,ts;
	void push(ll x){
		t1.PB(x);
		s1.insert(x);
		sum+=x;
		if((int)s1.size()>k){
			auto it=--s1.end();
			t2.PB(*it);
			sum-=*it;
			s2.insert(*it);
			s1.erase(it);
		}
	}
	void nxt(){
		k++;
		if(s2.empty()) return;
		auto it=s2.begin();
		sum+=*it;
		s1.insert(*it);
		s2.erase(it);
	}
	void rec(){
		t1.clear();
		t2.clear();
		ts=sum;
	}
	void reset(){
//		printf("used %d\n",(int)t1.size()+(int)t2.size());
//		t1.clear();t2.clear();
//		s1.clear();s2.clear();
		while(!t2.empty()){
			s1.insert(t2.back());
			auto it=s2.lower_bound(t2.back());
			s2.erase(it);
			t2.pop_back();
		}
		while(!t1.empty()){
			auto it=s1.lower_bound(t1.back());
			s1.erase(it);
			t1.pop_back();
		}
		sum=ts;
	}
}fq[maxn],gq[maxn];
void dfs(int u){
//	printf("u=%d\n",u);
	vis[u]=cur;
	f[u]=g[u]=sum[u];
	fq[u].nxt();
	if(cur!=1) gq[u].nxt();
	fq[u].rec();
	gq[u].rec();
	FOR(i,0,(int)e[u].size()-1){
		int v=e[u][i].first,w=e[u][i].second;
		if(vis[v]==cur) continue;
		if(deg[v]<=cur) break;
		dfs(v);
		f[u]+=f[v]+w;
		g[u]+=f[v]+w;
		fq[u].push(min(g[v],f[v]+w)-(f[v]+w));
		gq[u].push(min(g[v],f[v]+w)-(f[v]+w));
	}
	f[u]+=fq[u].sum;
	g[u]+=gq[u].sum;
	fq[u].reset();
	gq[u].reset();
}
vector<ll> minimum_closure_costs(int N,vector<int> U,vector<int> V,vector<int> W){
	n=N;
	vector<ll> vec(n,0);
	FOR(i,0,n-2){
		int u=U[i],v=V[i],w=W[i];
		add(u,v,w);add(v,u,w);
		vec[0]+=w;
		deg[u]++;deg[v]++;
	}
	FOR(i,1,n) sort(e[i].begin(),e[i].end(),cmp);
//	clock_t st=clock();
	vector<int> p,q;
	FOR(i,1,n) p.PB(i);
	FOR(i,1,n-1){
		cur=i;
		q.clear();
		FOR(jj,0,(int)p.size()-1){
			int j=p[jj];
			if(deg[j]==i){
				FOR(k,0,(int)e[j].size()-1){
					int v=e[j][k].first,w=e[j][k].second;
					sum[v]+=w;
					fq[v].push(-w);
					gq[v].push(-w);
				}
			}
			else q.PB(j);
		}
		p=q;
		FOR(jj,0,(int)p.size()-1){
			int j=p[jj];
			if(vis[j]!=i) dfs(j),vec[i]+=f[j];
		}
//		if(i%100==0) printf("%d\n",clock()-st),st=clock();
	}
	return vec;
}
int main() {
//	freopen("roads.in","r",stdin);
  int N;
  assert(1 == scanf("%d", &N));

  std::vector<int> U(N - 1), V(N - 1), W(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    assert(3 == scanf("%d %d %d", &U[i], &V[i], &W[i]));
  }

  std::vector<long long> closure_costs = minimum_closure_costs(N, U, V, W);
  for (int i = 0; i < static_cast<int>(closure_costs.size()); ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("%lld",closure_costs[i]);
  }
  printf("\n");
  return 0;
}