#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,x,a[maxn],f[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		x=read();
		for(int i=1;i<=n;i++) a[i]=read();
		multiset<int> s;
		int l=1;
		for(int i=1;i<=n;i++){
			s.insert(a[i]);
			while(*--s.end()-*s.begin()>x*2) s.erase(s.find(a[l++]));
			f[i]=f[l-1]+1;
		}
		printf("%d\n",f[n]-1);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}