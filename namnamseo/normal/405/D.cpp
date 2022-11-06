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

int chk[1000010];
int n;
int dat[500010];

int main(){
	read(n);
	int S = int(1e6);
	for(int i=0; i<n; ++i){
		int x; read(x);
		dat[i]=x; chk[x]=true;
	}
	int unm = 0;
	vector<int> ans;
	for(int i=0; i<n; ++i){
		int x=dat[i];
		if(chk[x] && chk[S+1-x]) ++unm;
		else {
			ans.push_back(S+1-x);
		}
	}
	for(int i=1; i<=S; ++i){
		if(!unm) break;
		if(!chk[i] && !chk[S+1-i]){
			--unm; --unm;
			ans.pb(i); ans.pb(S+1-i);
		}
	}
	printf("%d\n",sz(ans));
	for(int a : ans) printf("%d\n", a);
	return 0;
}