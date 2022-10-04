#include<cstdio>
#include<algorithm>
#include<cstring>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define F2(i,a,b) for(int i=a;i<b;++i)
int n,w,h,g[100002],p[100002],t[100002],I[100002],Ans[100002],Ansg[100002];
inline bool cmp(int x,int y){
	if(p[x]-t[x]<p[y]-t[y]) return 1;
	else if(p[x]-t[x]>p[y]-t[y]) return 0;
	else{
		if(g[x]>g[y]) return 1;
		else if(g[x]<g[y]) return 0;
		else{
			if(g[x]==1) return p[x]<p[y];
			else return p[x]>p[y];
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&w,&h);
	F(i,1,n) scanf("%d%d%d",g+i,p+i,t+i),I[i]=i;
	std::sort(I+1,I+n+1,cmp);
	I[n+1]=0; p[0]=99999999; t[0]=-99999999;
	int hor=0,ver=0;
	F(i,1,n){
		if(g[I[i]]==1) ++ver; else ++hor;
		if(p[I[i]]-t[I[i]]!=p[I[i+1]]-t[I[i+1]]){
			int j=i-hor-ver+1, k=i-ver+1,l,o;
			for(l=k,o=j;l<=i;++l,++o)
				Ans[I[o]]=p[I[l]],Ansg[I[o]]=g[I[l]];
			for(;o<=i;++o,++j)
				Ans[I[o]]=p[I[j]],Ansg[I[o]]=g[I[j]];
			ver=hor=0;
		}
	}
	F(i,1,n) if(Ansg[i]==1) printf("%d %d\n",Ans[i],h); else printf("%d %d\n",w,Ans[i]);
	return 0;
}