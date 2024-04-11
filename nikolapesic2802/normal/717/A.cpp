#include <iostream>
#define ll long long
#define MOD 1000000007
ll inv(int a,int p=MOD){return a==1?1:(1+p*(a-inv(p%a,a)))/a%p;}
struct num{ // a+b*sqrt(5)
	int a,b;
	num(int a=0,int b=0){this->a=a;this->b=b;}
	num operator+(num x){return num((a+x.a)%MOD,(b+x.b)%MOD);}
	num operator-(num x){return num((a-x.a+MOD)%MOD,(b-x.b+MOD)%MOD);}
	num operator*(num x){return num((1ll*a*x.a+5ll*b*x.b)%MOD,(1ll*a*x.b+1ll*b*x.a)%MOD);}
};
num pow(num a,ll n,bool t=0){
	num p=1,s=0;
	int i=0;while(n>>i)i++;
	while(i--){
		s=s*(p+1),p=p*p;
		if(n>>i&1)s=s+p,p=p*a;
	}
	return t?s:p;
}
ll a[210],C[210];
num pA[210],pB[210];
int main(){
	int k;ll l,r;
	std::cin>>k>>l>>r;
	*pA=*pB=*a=*C=1;
	for(int i=1;i<=k;(*a*=MOD+2-++i)%=MOD){
		for(int j=i;j;j--)a[j]=(a[j-1]+a[j]*(MOD-i+1))%MOD;
		pA[i]=pow(num(inv(2),inv(2)),i);
		pB[i]=pow(num(inv(2),MOD-inv(2)),i);
	}
	num S=0,c=*a,x;
	for(int i=0;i<=k;i++,c=pow(num(0,inv(5)),i)*a[i]){
		for(int j=i;j>=0;j--){
			x=(pow(pA[j]*pB[i-j],r+3,1)-pow(pA[j]*pB[i-j],l+2,1))*(j?(C[j]+=C[j-1])%=MOD:1)*c;
			i-j&1?S=S-x:S=S+x;
		}
	}
	for(int i=1;i<=k;i++)S=S*inv(i);
	std::cout<<S.a<<'\n';
}