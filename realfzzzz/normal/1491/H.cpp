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
const int maxn=1e5+5,maxb=350;
int n,q,a[maxn];
int S,B,pos[maxn],L[maxb],R[maxb];
int pre[maxn],mx[maxb],tag[maxb];
void modify(int l,int r,int k){
	int x=pos[r];
	for(int i=L[x];i<=R[x];i++) a[i]=max(a[i]-tag[x],1);
	tag[x]=0;
	for(int i=l;i<=r;i++) a[i]=max(a[i]-k,1);
	mx[x]=0;
	for(int i=L[x];i<=R[x];i++){
		pre[i]=a[i]<L[x]?a[i]:pre[a[i]];
		mx[x]=max(mx[x],a[i]);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	q=readint();
	for(int i=2;i<=n;i++) a[i]=readint();
	S=sqrt(n);
	B=(n-2)/S+1;
	for(int i=1;i<=B;i++){
		L[i]=(i-1)*S+2;
		R[i]=min(i*S+1,n);
		for(int j=L[i];j<=R[i];j++){
			pos[j]=i;
			pre[j]=a[j]<L[i]?a[j]:pre[a[j]];
			mx[i]=max(mx[i],a[j]);
		}
	}
	while(q--){
		int opt=readint();
		if(opt==1){
			int l,r,x;
			l=readint();
			r=readint();
			x=readint();
			if(pos[l]==pos[r]){
				modify(l,r,x);
				continue;
			}
			modify(l,R[pos[l]],x);
			for(int i=pos[l]+1;i<pos[r];i++)
				if(mx[i]<L[i]) tag[i]=min(tag[i]+x,n);
				else modify(L[i],R[i],x);
			modify(L[pos[r]],r,x);
		}
		else{
			int u,v;
			u=readint();
			v=readint();
			auto getpre=[](int x){
				if(mx[pos[x]]>=L[pos[x]]) return pre[x];
				else return max(a[x]-tag[pos[x]],1);
			};
			while(getpre(u)!=getpre(v)){
				if(pos[u]<pos[v]) swap(u,v);
				u=getpre(u);
			}
			while(u!=v){
				if(u<v) swap(u,v);
				u=max(a[u]-tag[pos[u]],1);
			}
			printf("%d\n",u);
		}
	}
	return 0;
}