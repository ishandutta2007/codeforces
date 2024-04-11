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
//void read(ll& x){ scanf("%I64d",&x); }
void read(ll& x){ cin >> x; }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

bool unread[300001];
queue<pp> chronot;
queue<int> my[300001];

int main(){
	int n,q; read(n, q);
	int nt = 0;
	int sum=0;
	for(;q--;){
		int com, x; read(com, x);
		if(com == 1){
			unread[++nt] = true;
			chronot.push(pp(nt, x));
			my[x].push(nt);
			++sum;
		} else if(com == 2){
			while(my[x].size()){
				int y=my[x].front(); my[x].pop();
				if(unread[y]) --sum;
				unread[y]=false;
			}
		} else {
			while(chronot.size()){
				if(chronot.front().first > x) break;
				int y=chronot.front().first;
				if(unread[y]) --sum;
				unread[y]=false;
				chronot.pop();
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}