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

const ll M=ll(1e9)+7;

ll inv2 = (M+1)/2;

#define pow asdf
ll pow(ll a,ll b){
	if(b==0) return 1;
	ll ret=pow(a, b/2);
	ret = (ret*ret)%M;
	if(b&1) ret=(ret*a)%M;
	return ret;
}

int main(){
	int k; read(k);
	ll pow_exp = 1;
	ll oddity = 1;
	ll two_base = 2;
	for(;k--;){
		ll a;
		read(a);
		pow_exp = (pow_exp * (a%(M-1))) % (M-1);
		oddity *= (a&1);
		two_base = pow(two_base, a%(M-1));
	}
	two_base = (two_base * inv2) % M;
	if(!oddity) two_base = (two_base + 1) % M;
	else        two_base = (two_base + M- 1) % M;
	ll ja = two_base * ((M+1)/3) % M;
	ll mo = pow(2, pow_exp + M - 2);
	printf("%I64d/%I64d\n", ja, mo);
	return 0;
}