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
void read(ll& x){ scanf("%I64d",&x); }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int n;
char data[3010];
vector<int> p;

int main(){
	read(n);
	scanf("%s",data+1);
	for(int i=1; i<=n; ++i){
		if(data[i]=='L') p.pb(i);
		else if(data[i]=='R') p.pb(-i);
	}
	if(p.size() == 0u) printf("%d\n",n);
	else {
		int sz=p.size();
		int ans = 0;
		for(int i=0; i<sz-1; ++i){
			int a=p[i], b=p[i+1];
			if(a>0 && b<0){
				ans += (-b)-a-1;
			} else {
				if((a+b)%2 == 0) ++ans;
			}
		}
		if(p[0] < 0){
			ans += (-p[0]) - 1;
		}
		if(p[sz-1] > 0){
			ans += n-p[sz-1];
		}
		printf("%d\n", ans);
	}
	return 0;
}