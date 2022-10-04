#include<cstdio>
#include<algorithm>
#include<cstring>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define F2(i,a,b) for(int i=a;i<b;++i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int n,a[200008][20],n2;
int l[200008],r[200008],s[200008],t;
long long Ans=0;
void init(){
	int n3;
	scanf("%d",&n); n3=n;
	while(n3) ++n2, n3>>=1; n3--;
	F(i,1,n) scanf("%d",&a[i][0]);
	F(j,1,n2){
		F(i,1,n-(1<<j)+1){
			a[i][j]=a[i][j-1]|a[i+(1<<(j-1))][j-1];
//			printf("%d ",a[i][j]);
		}
//		puts("");
	}
	a[0][0]=a[n+1][0]=2047483647;
	t=1; s[1]=0;
	F(i,1,n){
		while(t&&a[s[t]][0]<a[i][0]) --t;
		l[i]=s[t]+1;
		s[++t]=i;
	}
	t=1; s[1]=n+1;
	dF(i,n,1){
		while(t&&a[s[t]][0]<=a[i][0]) --t;
		r[i]=s[t]-1;
		s[++t]=i;
	}
//	F(i,1,n) printf("%d ",l[i]); puts("");
//	F(i,1,n) printf("%d ",r[i]); puts("");
}
int RMQ(int l,int r){
	int d=r-l+1;
	int dd=d,d2=0;
	while(dd) ++d2,dd>>=1; d2--;
	return a[l][d2]|a[r-(1<<d2)+1][d2];
}
int che1(int x){
	int L=0, R=x, M, A=-1;
	while(L<=R){
		M=(L+R)/2;
		if((RMQ(M,x)^a[x][0])!=0) A=M, L=M+1;
		else R=M-1;
	}
	return A;
}
int che2(int x){
	int L=x, R=n, M, A=-1;
	while(L<=R){
		M=(L+R)/2;
		if((RMQ(x,M)^a[x][0])!=0) A=M, R=M-1;
		else L=M+1;
	}
	return A;
}
int main(){
	init();
	F(i,1,n){
		int L1=che1(i), R1=che2(i);
		if(L1==-1||L1<l[i]) L1=l[i]-1;
		if(R1==-1||R1>r[i]) R1=r[i]+1;
		Ans+=1ll*(i-l[i]+1)*(r[i]-i+1)-1ll*(i-L1)*(R1-i);
	}
	printf("%I64d",Ans);
	return 0;
}