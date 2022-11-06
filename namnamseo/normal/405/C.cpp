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

int t[1010][1010];
int ans;
int n;

int main(){
	read(n);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			read(t[i][j]);
			if(i==j){
				if(t[i][j]) ans^=1;
			}
		}
	}
	int q;
	read(q);
	for(;q--;){
		int c; read(c);
		if(c==1){
			read(c);
			ans ^= 1;
		} else if(c==2){
			read(c);
			ans ^= 1;
		} else putchar(48+ans);
	}
	return 0;
}