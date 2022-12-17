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
const int maxn=1e6+5,maxq=5e5+5,m=1e5+5;
int n,q,a[maxn],opt[maxq],l[maxq],r[maxq],x[maxq];
int S,B,L,R,mx,red,fa[maxn],sz[maxn],p[m];
int find(int u){
	while(fa[u]!=u) u=fa[u]=fa[fa[u]];
	return u;
}
void merge(int x,int y){
	if(!p[x+red]) return;
	if(p[y+red]){
		fa[p[x+red]]=p[y+red];
		sz[p[y+red]]+=sz[p[x+red]];
	}
	else a[p[y+red]=p[x+red]]=y+red;
	p[x+red]=0;
}
void modify(int l,int r,int x){
	for(int i=L;i<=R;i++) p[a[i]=a[find(i)]]=0;
	for(int i=L;i<=R;i++) a[i]-=red;
	red=0;
	for(int i=l;i<=r;i++) if(a[i]>x) a[i]-=x;
	for(int i=L;i<=R;i++)
		if(!p[a[i]]){
			p[a[i]]=fa[i]=i;
			sz[i]=1;
		}
		else sz[fa[i]=p[a[i]]]++;
}
int query(int l,int r,int x){
	int cnt=0;
	for(int i=l;i<=r;i++) cnt+=a[find(i)]-red==x;
	return cnt;
}
int ans[maxq];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	S=max(sqrt(n)*0.9,1.0);
	B=(n-1)/S+1;
	for(int i=1;i<=q;i++){
		opt[i]=read();
		l[i]=read();
		r[i]=read();
		x[i]=read();
	}
	for(int t=1;t<=B;t++){
		L=S*(t-1)+1;
		R=min(S*t,n);
		mx=m-1;
		red=0;
		for(int i=L;i<=R;i++)
			if(!p[a[i]]){
				p[a[i]]=fa[i]=i;
				sz[i]=1;
			}
			else sz[fa[i]=p[a[i]]]++;
		for(int i=1;i<=q;i++)
			if(opt[i]==1){
				if(!x[i]) continue;
				if(r[i]<L||l[i]>R) continue;
				if(l[i]>=L||r[i]<=R){
					modify(max(l[i],L),min(r[i],R),x[i]);
					continue;
				}
				if(mx>=x[i]*2){
					for(int j=x[i];j>=0;j--) merge(j,j+x[i]);
					mx-=x[i];
					red+=x[i];
				}
				else if(mx>x[i]){
					for(int j=x[i]+1;j<=mx;j++) merge(j,j-x[i]);
					mx=x[i];
				}
			}
			else{
				if(r[i]<L||l[i]>R) continue;
				if(l[i]>=L||r[i]<=R){
					ans[i]+=query(max(l[i],L),min(r[i],R),x[i]);
					continue;
				}
				if(x[i]+red<m&&p[x[i]+red]) ans[i]+=sz[p[x[i]+red]];
			}
		for(int i=L;i<=R;i++) if(fa[i]==i) p[a[i]]=0;
	}
	for(int i=1;i<=q;i++) if(opt[i]==2) printf("%d\n",ans[i]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}