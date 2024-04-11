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

int k, n;
pp pk[10], pn[1010];

int gcd(int a, int b){ return b?gcd(b, a%b):a; }
pp operator-(pp a, pp b){ return {a.x-b.x, a.y-b.y}; }
pp reg(pp v){
	int g=gcd(abs(v.x), abs(v.y)); if(g){ v.x/=g; v.y/=g; }
	return v;
}
ll sz(pp v){ return abs(ll(v.x))+abs(v.y);}

int uchi[10][1010];

int Q[1010];
bitset<1000> vis;
int prm[10];

int main()
{
	read(k, n);
	for(int i=0; i<k; ++i) read(pk[i].x, pk[i].y);
	for(int i=0; i<n; ++i) read(pn[i].x, pn[i].y);
	for(int i=0; i<k; ++i){
		map<pp,vector<int>> m;
		for(int j=0; j<n; ++j) m[reg(pn[j]-pk[i])].pb(j);
		for(auto& _:m){
			auto& v=_.y;
			sort(all(v), [&](const int& a, const int& b){
				return sz(pn[a]-pk[i])<sz(pn[b]-pk[i]);
			});
			uchi[i][v[0]]=-1;
			for(int s=v.size(), j=1; j<s; ++j) uchi[i][v[j]]=v[j-1];
		}
	}
	int ans=0;
	for(int t=0; t<n; ++t){
		for(int i=0; i<k; ++i) prm[i]=i;
		bool ok=0;
		do {
			vis.reset();
			int head=1, tail=0; Q[0]=t; vis[t]=1;
			while(tail<head){
				if(tail>k+1) break;
				int from = prm[tail];
				int to = Q[tail];
				++tail;
				for(;;){
					to=uchi[from][to];
					if(to == -1) break;
					if(head>k+1) break;
					if(!vis[to]) vis[to]=1, Q[head++]=to;
				}
				if(head>k+1) break;
			}
			if(tail==head && head<=k){
				ok=1; break;
			}
		} while(next_permutation(prm, prm+k));
		ans += ok;
	}
	printf("%d\n", ans);
	return 0;
}