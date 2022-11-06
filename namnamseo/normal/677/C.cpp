#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
using namespace std;
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define coord_comp(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define v_index(v, x) (lower_bound(all(v),x)-(v).begin())
typedef pair<int,int> pp;
void read(int& x){ scanf("%d",&x); }
template<typename T1,typename T2>
void read(pair<T1,T2>& p){ read(p.first); read(p.second); }
template<typename T,typename... Args>
void read(T&a,Args&...b){ read(a); read(b...); }

char data[100010];

int main(){
	scanf("%s",data);
	int ans=1;
	for(int i=0; data[i]; ++i){
		int v=0;
		if(data[i]<=57 && 48<=data[i]) v=data[i]-48;
		if(data[i]>='A' && data[i]<='Z') v=data[i]-65+10;
		if(data[i]>='a' && data[i]<='z') v=data[i]-97+36;
		if(data[i]=='-') v=62;
		if(data[i]=='_') v=63;
		int j;
		for(j=0; j<6; ++j){
			if(1&(v>>j)){

			} else {
				ans=(ans*3ll)%(int(1e9)+7);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}