//shab rmj
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
const int maxs=(1<<18)+5;
int n,a[maxs],b[maxs],ord[maxs];
char s[maxs];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	scanf("%s",s);
	for(int i=0;i<(1<<n);i++) ord[i]=i;
	sort(ord,ord+(1<<n),[](int x,int y){
		return s[x]<s[y];
	});
	a[ord[0]]=0;
	for(int j=1;j<(1<<n);j++){
		int u=ord[j],v=ord[j-1];
		a[u]=s[u]==s[v]?a[v]:j;
	}
	for(int i=0;i<n;i++){
		auto cmp=[i](int x,int y){
			if(a[x]!=a[y]) return a[x]<a[y];
			return a[x^(1<<i)]<a[y^(1<<i)];
		};
		sort(ord,ord+(1<<n),cmp);
		b[ord[0]]=0;
		for(int j=1;j<(1<<n);j++){
			int u=ord[j],v=ord[j-1];
			b[u]=!cmp(u,v)&&!cmp(v,u)?b[v]:j;
		}
		for(int j=0;j<(1<<n);j++) a[j]=b[j];
	}
	for(int i=0;i<(1<<n);i++) printf("%c",s[i^ord[0]]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}