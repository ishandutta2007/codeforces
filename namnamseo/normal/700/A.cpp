#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(ll& x){ cin>>x; }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

#define double long double

int main(){
	ll n,l, v1, v2, k;
	read(n, l, v1, v2, k);
	int cnt=((n+k-1)/k-1);
	double t=v2 + (2.0*v2)/(v1+v2)*v1*cnt;
	double dt=l/t;
	double ans=(1+(2.0*v2)/(v1+v2)*cnt)*dt;
	cout << setprecision(20) << ans << endl;
	return 0;
}