#include <stdio.h>
#include <set>
#define MN 200000
const int INF = 0x7fffffff;

using std::set;

int n,a[MN+5];

int last(const set<int>& s,int x){
	auto it = s.find(x);
	if(it==s.begin()) return -INF;
	--it;
	return *it;
}

int next(const set<int>& s,int x){
	auto it = s.find(x);
	++it;
	if(it==s.end()) return INF;
	return *it;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	set<int> s;
	s.insert(a[1]);
	for(int i=2;i<=n;i++){
		s.insert(a[i]);
		if(a[i]!=a[i-1]&&last(s,a[i])!=a[i-1]&&next(s,a[i])!=a[i-1]){
			puts("NO");
			return;
		}
	}
	puts("YES");
	return;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}