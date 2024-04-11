#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 1000020
using namespace std;
int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,tmp,fs[M],nt[M<<1],to[M<<1],F[M],S[M],top,dst[M];
int ind[M],dep[M],u,v,rt[M],RT,L[M],R[M];
void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y,ind[x]++;}
int merge(int x,int y){
	if(!x||!y) return x|y;
	if(dep[x]<dep[y]) swap(x,y);
	R[x]=merge(R[x],y);
	if(dst[L[x]]<dst[R[x]]) swap(L[x],R[x]);
	dst[x]=dst[R[x]]+1;
	return x;
}
bool cmp(int x,int y){return dep[rt[x]]>dep[rt[y]];}
void dp(int x,int last){
	dep[x]=dep[last]+1,rt[x]=0;
	if(ind[x]==1){rt[x]=x;return;}
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]!=last) dp(to[i],x),F[x]+=F[to[i]];
	top=0;
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]!=last) S[++top]=to[i];
	sort(S+1,S+top+1,cmp);
	for(int i=1;i<=top;i++){
		if(dep[rt[S[i]]]-dep[x]==m){F[x]++;continue;}
		if(dep[rt[S[i]]]<=0) break;
		if(i==1){rt[x]=rt[S[i]];continue;}
		if(dep[rt[S[i]]]+dep[rt[x]]-2*dep[x]<=m) rt[x]=merge(rt[x],rt[S[i]]);
		else rt[x]=rt[S[i]],F[x]++;
	}
}
int main(){
	n=read(),m=read(),memset(fs,-1,sizeof(fs));
	for(int i=1;i<n;i++) u=read(),v=read(),link(u,v),link(v,u);
	for(int i=1;i<=n;i++) if(ind[i]>1){RT=i;break;}
	if(RT==0){puts("1");return 0;}
	dp(RT,0),printf("%d\n",F[RT]+(rt[RT]>0?1:0)); return 0;
}