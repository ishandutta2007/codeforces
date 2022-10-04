#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;
#define Mod 1000000007
#define MN 1000002
int n,k,a[MN],stk[MN],L[MN],R[MN],tp,Ans;

int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n) scanf("%d",a+i);
	a[0]=a[n+1]=0x3f3f3f3f;
	stk[tp=1]=0;
	F(i,1,n+1){
		while(tp&&a[stk[tp]]<a[i]) R[stk[tp]]=i-1, --tp;
		L[i]=stk[tp]+1;
		stk[++tp]=i;
	}
	F(i,1,n){
		int len=R[i]-L[i]+1;
		int M=min(i-L[i],R[i]-i)/(k-1);
		int S=0;
		S=(S+M+(LL)(M+1)*M/2%Mod*(k-1)%Mod)%Mod;
		int N=max(i-L[i],R[i]-i)/(k-1);
		S=(S+(LL)(N-M)*(min(i-L[i],R[i]-i)+1)%Mod)%Mod;
		int O=(len-1)/(k-1);
		S=(S+(LL)(O-N)*len%Mod-(LL)(O-N)*(O+N+1)/2%Mod*(k-1)%Mod+Mod)%Mod;
		Ans=(Ans+(LL)a[i]*S%Mod)%Mod;
	} printf("%d",Ans);
	return 0;
}