#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		int n,m;
		n=readint();
		m=readint();
		multiset<int> s;
		while(n--) s.insert(readint());
		long long ans=0;
		for(int i=1;i<=m;i++){
			int c=readint();
			if(s.size()){
				ans+=c;
				s.erase(--s.end());
				ans+=1ll*c*s.count(i);
				s.erase(i);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}