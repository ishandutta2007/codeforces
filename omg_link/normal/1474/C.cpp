#include <stdio.h>
#include <algorithm>
#include <set>

using std::multiset;

int n;
multiset<int> s;

bool check(int x,int y){
	multiset<int> s = ::s;
	int t = std::max(x,y);
	s.erase(s.find(x));
	s.erase(s.find(y));
	while(!s.empty()){
		x = *(--s.end());
		y = t-x;
		s.erase(s.find(x));
		if(s.find(y)==s.end())
			return false;
		s.erase(s.find(y));
		t = std::max(x,y);
	}
	return true;
}

void solve(){
	s.clear();
	scanf("%d",&n);
	for(int i=1,a;i<=2*n;i++){
		scanf("%d",&a);
		s.insert(a);
	}
	auto ls = --s.end();
	for(auto it=s.begin();it!=ls;it++){
		if(check(*it,*ls)){
			puts("YES");
			int x = *it;
			int y = *ls;
			int t = x+y;
			printf("%d\n",t);
			s.erase(s.find(x));
			s.erase(s.find(y));
			t = std::max(x,y);
			printf("%d %d\n",x,y);
			while(!s.empty()){
				x = *(--s.end());
				y = t-x;
				s.erase(s.find(x));
				s.erase(s.find(y));
				t = std::max(x,y);
				printf("%d %d\n",x,y);
			}
			return;
		}
	}
	puts("NO");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}