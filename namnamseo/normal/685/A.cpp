#include <bits/stdc++.h>
using namespace std;
#define sz(v) ((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
typedef long long ll;
void read(int& x){ scanf("%d",&x); }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int f7(int x){
	int ret=1, i;
	for(i=1;; ++i){
		ret*=7;
		if(ret>=x) return i;
	}
}

int b(int *s,int c){
	int ret=0;
	for(int i=0; i<c; ++i){
		ret=ret*7+s[i];
	}
	return ret;
}

set<pp> S;

int main(){
	int n,m;
	read(n,m);

	int d,e;
	d=f7(n); e=f7(m);

	if(d+e > 7){
		puts("0");
		return 0;
	}

	int p[7];
	for(int i=0; i<7; ++i){
		p[i]=i;
	}

	do {
		int ta=b(p,d);
		int tb=b(p+d,e);
		if(ta<n && tb<m){
			S.insert({ta,tb});
		}
	} while(next_permutation(p, p+7));

	printf("%d\n", (int) S.size());

	return 0;
}