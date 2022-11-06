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

int p[100010];

bool vis[100010];
int dfs(int x){
	if(vis[x]) return 0;
	vis[x]=1;
	return dfs(p[x])+1;
}

int main()
{
	int n;
	read(n);
	for(int i=1; i<=n; ++i) read(p[i]);
	priority_queue<int> pq;
	for(int i=1; i<=n; ++i) if(!vis[i]) pq.push(dfs(i));
	int s=0;
	for(int i=0; i<2; ++i) if(pq.size()) s+=pq.top(), pq.pop();
	pq.push(s);
	ll ans=0;
	while(pq.size()){
		ans += pq.top()*1LL*pq.top(); pq.pop();
	}
	printf("%lld\n", ans);
	return 0;
}