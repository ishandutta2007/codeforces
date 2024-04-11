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
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

int n,k;

bool cp  [1000010];
bool pr  [1000010];
vector<int> divs, cand;

int main(){
	read(n,k);
	if(k == 1){
		puts("Yes");
		return 0;
	}
	int MP=k;

	for(int i=1; i<=n; ++i){
		int buf; read(buf);
		cp[buf] = true;
		MP=max(MP, buf);
	}

	for(int i=2; i<=MP; ++i){
		if(pr[i]) continue;
		for(int j=i*2; j<=MP; j+=i){
			pr[j]=true;
			if(cp[j]){
				int t=j, T=1;
				while(t%i == 0){
					t/=i; T*=i;
					divs.pb(T);
				}
			}
		}
		if(cp[i]) divs.pb(i);
		int cnt = 0, po=1;
		int t=k;
		while(t % i == 0){
			++cnt;
			po *= i; t /= i;
		}
		if(po > 1)
			cand.pb(po);
	}

	set<int> divv(all(divs));
	for(int v : cand){
		if(divv.find(v) == divv.end()){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}