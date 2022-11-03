#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
#define ll long long
il ll gi(){
	ll x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
il int Pow(int a,ll b){
	int ret=1;
	while(b){
		if(b&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;b>>=1;
	}
	return ret;
}
struct number{
	int a,b;
	number inv()const{
		int fm=Pow((1ll*a*a-5ll*b*b%mod+mod)%mod,mod-2);
		return (number){1ll*a*fm%mod,(mod-1ll*b*fm%mod)%mod};
	}
};//a+b*sqrt(5)
il number getnum(int x){return(number){x,0};}
il number operator+(const number&a,const number&b){return(number){(a.a+b.a)%mod,(a.b+b.b)%mod};}
il number operator-(const number&a,const number&b){return(number){(a.a-b.a+mod)%mod,(a.b-b.b+mod)%mod};}
il number operator*(const number&a,const number&b){return(number){(1ll*a.a*b.a+5ll*a.b*b.b)%mod,(1ll*a.a*b.b+1ll*a.b*b.a)%mod};}
il number operator/(const number&a,const number&b){return a*b.inv();}
il number Pow(number a,ll b){
	number ret=getnum(1);
	while(b){
		if(b&1)ret=ret*a;
		a=a*a;b>>=1;
	}
	return ret;
}
ll k,l,r;
int A[410],B[410],C[410][410];
number p1[410],p2[410],p3[410];
il number solve(ll n){
	number ans=getnum(0);
	for(int i=0;i<=k;++i){
		number res=getnum(0);
		for(int o=0;o<=i;++o){
			number _res=getnum(1ll*C[i][o]*(i-o&1?mod-1:1)%mod);
			number a=p2[o]*p3[i-o];
			if(a.a==1&&a.b==0)_res=_res*getnum(n%mod);
			else _res=_res*((Pow(a,n+1)-a)/(a-getnum(1)));
			res=res+_res;
		}
		ans=ans+res*getnum(A[i])*p1[i];
	}
	return ans;
}
int main(){
	k=gi(),l=gi(),r=gi();
	A[0]=1;
	for(int i=0;i<k;++i){
		memcpy(B,A,sizeof A);
		memset(A,0,sizeof A);
		for(int j=0;j<=k;++j)A[j]=mod-1ll*B[j]*i%mod;
		for(int j=0;j<=k;++j)A[j+1]=(A[j+1]+B[j])%mod;
	}
	C[0][0]=1;
	for(int i=1;i<=k;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	p1[0]=p2[0]=p3[0]=getnum(1);
	p1[1]=(number){1,0}/(number){0,1};
	p2[1]=(number){1,1}/(number){2,0};
	p3[1]=(number){1,mod-1}/(number){2,0};
	for(int i=2;i<=k;++i)p1[i]=p1[i-1]*p1[1],p2[i]=p2[i-1]*p2[1],p3[i]=p3[i-1]*p3[1];
	number ans=solve(r+2)-solve(l+1);
	for(int i=1;i<=k;++i)ans.a=1ll*ans.a*Pow(i,mod-2)%mod;
	printf("%d\n",ans.a);
	return 0;
}