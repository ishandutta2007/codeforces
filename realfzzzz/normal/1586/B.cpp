#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
		set<int> s;
		for(int i=1;i<=n;i++) s.insert(i);
		while(m--){
			readint();
			s.erase(readint());
			readint();
		}
		int x=*s.begin();
		for(int i=1;i<=n;i++) if(i!=x) printf("%d %d\n",i,x);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}