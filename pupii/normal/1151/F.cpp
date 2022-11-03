#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
struct matrix{
	int s[101][101];
	matrix(){memset(s,0,sizeof s);}
};
matrix operator*(const matrix&A,const matrix&B){
	matrix r;
	for(int j=0;j<101;++j)
		for(int i=0;i<101;++i)
			for(int k=0;k<101;++k)
				r.s[i][k]=(r.s[i][k]+1ll*A.s[i][j]*B.s[j][k])%mod;
	return r;
}
matrix operator^(matrix A,int b){
	matrix r;for(int i=0;i<101;++i)r.s[i][i]=1;
	while(b){
		if(b&1)r=r*A;
		A=A*A;b>>=1;
	}
	return r;
}
int a[110];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),k=gi(),c[2]={0};
	for(int i=1;i<=n;++i)++c[a[i]=gi()];
	int A=c[0],B=c[1],C=0;
	for(int i=1;i<=A;++i)C+=!a[i];
	matrix S,T;
	S.s[0][C]=1;
	int iCn=pow(n*(n-1)/2,mod-2),CA=A*(A-1)/2,CB=B*(B-1)/2;
	for(int i=0;i<=A;++i){
		if(i)T.s[i][i-1]=1ll*i*(B-A+i)*iCn%mod;
		T.s[i][i]=1ll*((B-A+i+i)*(A-i)+CA+CB)*iCn%mod;
		T.s[i][i+1]=1ll*(A-i)*(A-i)*iCn%mod;
	}
	S=S*(T^k);
	printf("%d\n",S.s[0][A]);
	return 0;
}