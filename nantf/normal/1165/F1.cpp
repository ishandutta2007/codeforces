#include<bits/stdc++.h>
using namespace std;
const int maxn=200020,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,k[maxn],d[maxn],t[maxn],kk[maxn],at[maxn],p[maxn];
bool cmp(int x,int y){
	return at[x]<at[y];
}
bool check(int x){
//	printf("check(%d)\n",x);
	MEM(at,0);
	FOR(i,1,m) if(d[i]<=x) at[t[i]]=max(at[t[i]],d[i]);
	FOR(i,1,n) p[i]=i,kk[i]=k[i];
	sort(p+1,p+n+1,cmp);
	int d=0;
	FOR(i,1,n) if(at[p[i]]){
		int use=at[p[i]]-d;
		if(use>=kk[p[i]]) d+=kk[p[i]],kk[p[i]]=0;
		else d+=use,kk[p[i]]-=use;
//		printf("at[%d]=%d,d=%d,use=%d\n",p[i],at[p[i]],d,use);
	}
	int rem=x-d,s=0;
	FOR(i,1,n) s+=kk[i];//,printf("kk[%d]=%d\n",i,kk[i]);
	return s*2<=rem;
}
int main(){
	n=read();m=read();
	FOR(i,1,n) k[i]=read();
	FOR(i,1,m) d[i]=read(),t[i]=read();
	int l=1,r=6e5;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}