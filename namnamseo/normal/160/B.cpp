#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <string>
#include <stack>
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

char data[210];
int n;

int main(){
	read(n);
	scanf("%s",data);
	sort(data,data+n);
	sort(data+n,data+2*n);
	int cnt[2]={0,0};
	int i;
	for(i=0;i<n;++i){
		if(data[i]<data[i+n]) ++cnt[1];
		else if(data[i]>data[i+n]) ++cnt[0];
	}
	if(cnt[0]==n || cnt[1]==n){
		puts("YES");
	} else puts("NO");
	return 0;
}