#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200020;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,p[maxn],id[maxn],st[maxn][19],logt[maxn];
ll ans;
int query(int l,int r){
	int k=logt[r-l+1],x=st[l][k],y=st[r-(1<<k)+1][k];
	return p[x]>p[y]?x:y;
}
void solve(int l,int r){
	if(l>=r) return;
	int x=query(l,r);
	if(x-l<r-x) FOR(i,l,x-1){
		if(id[p[x]-p[i]]>x && id[p[x]-p[i]]<=r) ans++;
	}
	else FOR(i,x+1,r) if(id[p[x]-p[i]]<x && id[p[x]-p[i]]>=l) ans++;
	solve(l,x-1);
	solve(x+1,r);
}
int main(){
	n=read();
	FOR(i,1,n) id[p[i]=read()]=i,st[i][0]=i;
	logt[1]=0;
	FOR(i,2,n) logt[i]=logt[i>>1]+1;
	FOR(j,1,18) FOR(i,1,n-(1<<j)+1){
		int x=st[i][j-1],y=st[i+(1<<(j-1))][j-1];
		st[i][j]=p[x]>p[y]?x:y;
	}
	solve(1,n);
	cout<<ans<<endl;
}