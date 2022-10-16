#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,x[maxn],y[maxn],p[maxn];
char s[maxn];
bool vis[maxn];
inline ll cross(int x1,int y1,int x2,int y2){
	return 1ll*x1*y2-1ll*x2*y1;
}
inline ll cross(int i,int j,int k){
	return cross(x[j]-x[i],y[j]-y[i],x[k]-x[i],y[k]-y[i]);
}
int main(){
	n=read();
	FOR(i,1,n){
		x[i]=read(),y[i]=read();
		if(!p[1] || x[i]<x[p[1]]) p[1]=i; 
	}
	scanf("%s",s+1);
	vis[p[1]]=true;
	FOR(i,1,n-2){
		FOR(j,1,n){
			if(vis[j]) continue;
			if(!p[i+1] || s[i]=='L' && cross(p[i],j,p[i+1])>0 || s[i]=='R' && cross(p[i],j,p[i+1])<0) p[i+1]=j;
		}
		vis[p[i+1]]=true;
	}
	FOR(i,1,n-1) printf("%d ",p[i]);
	FOR(i,1,n) if(!vis[i]) printf("%d\n",i);
}