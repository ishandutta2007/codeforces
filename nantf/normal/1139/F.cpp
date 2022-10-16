#include<bits/stdc++.h>
using namespace std;
const int maxn=400040;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct node{
	int pos,x,y,tp,id;
	bool operator<(const node &nd)const{
		if(pos!=nd.pos) return pos<nd.pos;
		return tp<nd.tp;
	}
}nd[maxn];
int n,m,sz,p[maxn],s[maxn],b[maxn],inc[maxn],pref[maxn],tmp[maxn],tl,nl,ans[maxn],bit[2][maxn];
inline int at(int x){
	return lower_bound(tmp+1,tmp+sz+1,x)-tmp;
}
inline void update(int id,int p,int v){
	for(int i=p;i<=sz;i+=i&-i) bit[id][i]+=v;
}
inline int query(int id,int p){
	int s=0;
	for(int i=p;i;i-=i&-i) s+=bit[id][i];
	return s;
}
int main(){
	n=read();m=read();
	FOR(i,1,n) p[i]=read();
	FOR(i,1,n) s[i]=read();
	FOR(i,1,n) b[i]=read();
	FOR(i,1,m) inc[i]=read();
	FOR(i,1,m) pref[i]=read();
	FOR(i,1,n) tmp[++tl]=b[i]+p[i],tmp[++tl]=b[i]-p[i]+1;
	FOR(i,1,m) tmp[++tl]=pref[i]+inc[i],tmp[++tl]=pref[i]-inc[i];
	sort(tmp+1,tmp+tl+1);sz=unique(tmp+1,tmp+tl+1)-tmp-1;
	FOR(i,1,n) nd[++nl]=(node){p[i],b[i],p[i],1,0},nd[++nl]=(node){s[i]+1,b[i],p[i],-1,0};
	FOR(i,1,m) nd[++nl]=(node){inc[i],pref[i],inc[i],2,i};
	sort(nd+1,nd+nl+1);
	FOR(i,1,nl){
		if(nd[i].tp!=2){
			update(0,at(nd[i].x-nd[i].y+1),nd[i].tp);
			update(1,at(nd[i].x+nd[i].y),nd[i].tp);
		}
		else ans[nd[i].id]=query(1,at(nd[i].x+nd[i].y))-query(0,at(nd[i].x-nd[i].y));
	}
	FOR(i,1,m) printf("%d ",ans[i]);
}