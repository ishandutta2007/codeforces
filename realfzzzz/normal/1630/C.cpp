#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int n,a[maxn],fst[maxn];
const int inf=2e9;
int c[maxn];
void modify(int x,int k){
	while(x){
		c[x]=max(c[x],k);
		x-=x&-x;
	}
}
int query(int x){
	int s=-inf;
	while(x<=n){
		s=max(s,c[x]);
		x+=x&-x;
	}
	return s;
}
int f[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
		if(!fst[a[i]]) fst[a[i]]=i;
	for(int i=1;i<=n;i++) c[i]=-inf;
	for(int i=1;i<=n;i++){
		if(i==fst[a[i]]) f[i]=f[i-1];
		else f[i]=i-1+query(fst[a[i]]);
		modify(i,f[i]-i);
	}
	printf("%d\n",f[n]);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}