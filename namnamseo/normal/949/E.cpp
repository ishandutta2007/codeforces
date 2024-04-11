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

vector<int> q[19], an[19];

void SU(vector<int>& v){
	sort(all(v));
	v.erase(unique(all(v)), v.end());
}

void solve(int T){
	an[T].clear();
	
	if(T == 18){
		for(int t:q[T]){
			if(t) an[T].pb(-t);
		}
		SU(an[T]);
		return;
	}
	if(q[T].empty()) return;
	
	bool le=0;
	for(int x:q[T]) if(1&(x>>T)) { le=1; break; }
	
	if(!le){
		q[T+1]=q[T];
		solve(T+1);
		an[T]=an[T+1];
		return;
	}
	
	for(int df=-1; df<=1; df+=2){
		q[T+1].clear();
		for(int x:q[T]){
			if(1&(x>>T)) x-=df*(1<<T);
			if(x) q[T+1].pb(x);
		}
		SU(q[T+1]);
		solve(T+1);
		an[T+1].pb(df*(1<<T));
		if(df==-1 || an[T].size()>an[T+1].size()) an[T]=an[T+1];
	}
}

int main()
{
	int n; read(n);
	for(int i=0; i<=18; ++i) q[i].reserve(100000), an[i].reserve(100000);
	
	for(int x,i=0; i<n; ++i) read(x), q[0].pb(x);
	solve(0);
	printf("%d\n", int(an[0].size()));
	for(int x:an[0]) printf("%d ", x);
	return 0;
}