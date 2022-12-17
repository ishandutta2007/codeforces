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
const int maxn=2e5+5;
int n,m,q,f[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	q=readint();
	set<pair<int,int>> s;
	for(int i=1;i<=q;i++){
		int a,b;
		a=readint();
		b=readint();
		if(n>m) swap(a,b);
		s.insert({a,b});
	}
	if(n>m) swap(n,m);
	f[1]=1;
	int ans=0;
	for(;f[n]<m;ans++) for(int i=n;i>0;i--) if(f[i]){
		int k=i+f[i]+s.count({i,f[i]});
		f[min(k,n)]=max(f[min(k,n)],f[i]);
		f[i]=min(k,m);
	}
	printf("%d\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}