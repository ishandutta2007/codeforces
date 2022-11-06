#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int ca[5], cb[5];

int main(){
	int n,m;
	read(n,m);
	for(int i=1; i<=n; ++i) ++ca[i%5];
	for(int i=1; i<=m; ++i) ++cb[i%5];
	ll ans=0;
	for(int i=0; i<5; ++i){
		ans += ca[i]*1LL*cb[(5-i)%5];
	}
	printf("%I64d\n",ans);
	return 0;
}