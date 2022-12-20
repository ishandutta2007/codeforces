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
const int maxn=1e5+5,maxs=350,maxb=350;
int n,k,lst[maxn],pre[maxn];
int S,B,L[maxb],R[maxb],pos[maxn];
int c[maxn],mn[maxb],add[maxb];
const ll mod=998244353;
ll f[maxn],s[maxb][maxs];
void modify2(int l,int r,int k){
	int x=pos[r];
	for(int i=l;i<=r;i++) c[i]+=k;
	mn[x]=n;
	for(int i=L[x];i<=R[x];i++)
		mn[x]=min(mn[x],c[i]+=add[x]);
	add[x]=0;
	memset(s[x],0,sizeof(s[x]));
	for(int i=L[x];i<=R[x];i++)
		s[x][c[i]-mn[x]]=(s[x][c[i]-mn[x]]+f[i-1])%mod;
	for(int i=1;i<S;i++) s[x][i]=(s[x][i]+s[x][i-1])%mod;
}
void modify(int l,int r,int k){
	if(pos[l]==pos[r]){
		modify2(l,r,k);
		return;
	}
	modify2(l,R[pos[l]],k);
	for(int i=pos[l]+1;i<pos[r];i++){
		mn[i]+=k;
		add[i]+=k;
	}
	modify2(L[pos[r]],r,k);
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	k=read();
	S=sqrt(n);
	B=n/S+1;
	for(int i=1;i<=B;i++){
		L[i]=S*(i-1)+1;
		R[i]=min(S*i,n+1);
		for(int j=L[i];j<=R[i];j++) pos[j]=i;
	}
	f[0]=1;
	for(int i=0;i<S;i++) s[1][i]=1;
	for(int i=1;i<=n;i++){
		int a=read();
		pre[i]=lst[a];
		lst[a]=i;
		modify(pre[i]+1,i,1);
		if(pre[i]) modify(pre[pre[i]]+1,pre[i],-1);
		int x=pos[i+1];
		for(int j=1;j<x;j++) if(mn[j]<=k)
			f[i]=(f[i]+s[j][min(k-mn[j],S-1)])%mod;
		for(int j=L[x];j<=i;j++)
			if(c[j]+add[x]<=k) f[i]=(f[i]+f[j-1])%mod;
		for(int j=0;j<S;j++) s[x][j]=(s[x][j]+f[i])%mod;
	}
	printf("%lld\n",f[n]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}