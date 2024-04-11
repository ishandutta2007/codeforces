#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000100;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,x,a[maxn],l[maxn],r[maxn],nxt[maxn],pre[maxn],hhh;
ll ans;
int main(){
	n=read();x=read();
	FOR(i,0,x+1) l[i]=n+1,r[i]=0;
	FOR(i,1,n){
		a[i]=read();
		if(l[a[i]]==n+1) l[a[i]]=i;
		r[a[i]]=i;
	}
	hhh=0;
	FOR(i,1,x){
		pre[i]=hhh;
		if(r[i]) hhh=i;
	}
	hhh=x+1;
	ROF(i,x,1){
		nxt[i]=hhh;
		if(r[i]) hhh=i;
	}
	int j=x;
	while(j && (!pre[j] || l[j]>r[pre[j]])) j=pre[j];
	j=pre[j];
	FOR(i,1,x){
		j=max(j,i);
		while(j<=x && pre[i] && l[nxt[j]]<r[pre[i]]) j=nxt[j];
		if(j>x) break;
		ans+=x-j+1;
		if(pre[i] && l[i]<r[pre[i]]) break;
	}
	cout<<ans<<endl;
}