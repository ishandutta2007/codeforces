#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#define For(i,a) for(int i=1;i<=a;++i)
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dFor(i,a) for(int i=a;i>=1;--i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
#define eF(h,i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
int n,m,k,s[100009];
int a[100009],b[100009],t=0;
long long ans=0;
void init(){
	scanf("%d%d%d",&n,&k,&m);
	For(i,n) scanf("%d",s+i);
	For(i,n){
		if(s[i]!=a[t])
			a[++t]=s[i], b[t]=1;
		else{
			++b[t];
			if(b[t]==k) ans+=k, --t;
		}
	} ans*=m;
}
int main(){
	init();
//	For(i,t) printf("%d %d, ",a[i],b[i]); puts("");
//	printf("%I64d\n",ans);
	int l=1, r=t;
	while(l<=r){
		if(a[l]!=a[r]) break;
		if(l==r) {ans+=1ll*b[l]*m/k*k; break;}
		if(b[l]+b[r]>=k){
			ans+=1ll*k*(m-1);
			if(b[l]+b[r]==k) ++l, --r;
			else break;
		}else break;
	}
	if(l==r&&1ll*b[l]*m%k==0) ans=1ll*n*m;
	printf("%I64d",1ll*n*m-ans);
	return 0;
}