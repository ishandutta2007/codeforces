#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define LL long long
#define Mod 998244353
int n,m,q,k;
int a[MN],b[MN],c[MN];
int h[MN],nxt[MM],to[MM],tot;
int f[MN],g[MN];
inline int DP(int*a,int n){
	if(!n)return 1;
	F(i,2,n)if(a[i]!=-1&&a[i-1]==a[i])return 0;
	if(k==1&&n>=2)return 0;
	int lst=a[1]!=-1?a[1]:0;
	if(a[1]==-1)f[1]=0,g[1]=1;
	else f[1]=1,g[1]=0;
	F(i,2,n){
		if(a[i]==-1){
			if(lst){
				f[i]=(LL)(k-1)*g[i-1]%Mod;
				g[i]=(f[i-1]+(LL)(k-2)*g[i-1])%Mod;
			}else{
				g[i]=(LL)(k-1)*g[i-1]%Mod;
				f[i]=0;
			}
		}
		else{
			if(lst) f[i]=(a[i]==lst?(LL)(k-1)*g[i-1]:f[i-1]+(LL)(k-2)*g[i-1])%Mod;
			else f[i]=(LL)(k-1)*g[i-1]%Mod;
			g[i]=0;
			lst=a[i];
		}
	}
	if(!lst)return (LL)k*g[n]%Mod;
	return (f[n]+(LL)(a[n]==-1?k-1:1)*g[n])%Mod;
} // f:==lst, g:!=lst
int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)if(i&1)b[i/2+1]=a[i];else c[i/2]=a[i];
	printf("%lld\n",(LL)DP(b,(n+1)/2)*DP(c,n/2)%Mod);
	return 0;
}

// lg