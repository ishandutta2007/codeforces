#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
typedef long long LL;
const LL mo=1e9+7;
LL f,w,h;
LL fac[maxn],inv[maxn];
LL C(LL n,LL m){
	if(m>n||m<0||n<0)return 0;
	return fac[n]*inv[m]%mo*inv[n-m]%mo;
}
 
LL pw(LL x,LL k,LL mo){
	LL ans=1;
	for(;k;k>>=1){
		if(k&1)ans=ans*x%mo;
		x=x*x%mo;
	}
	return ans;
}
 
LL P(LL n,LL m,LL w){
	if(n<0)return 0;
	return C(n-(w-1)*m-1,m-1);
}
 
int main(){
	fac[0]=1;
	for(int i=1;i<maxn;i++)
		fac[i]=fac[i-1]*i%mo;
	inv[0]=inv[1]=1;
	for(int i=2;i<maxn;i++)
		inv[i]=(mo-mo/i)*inv[mo%i]%mo;
	for(int i=1;i<maxn;i++)
		inv[i]=inv[i-1]*inv[i]%mo;
			
	cin>>f>>w>>h;
 
	if(w==0){
		puts("1");
		return 0;
	}
 
	LL p=0,q=0;
 
	for(int i=1;i<=w;i++){
		LL tmp1=P(w,i,h+1);
		LL tmp2=P(f-(i-1),i+1,0);
		p+=tmp1*tmp2%mo;
		p%=mo;
	}
	for(int i=1;i<=w;i++){
		LL tmp1=P(w,i,1);
		LL tmp2=P(f-(i-1),i+1,0);
		q+=tmp1*tmp2%mo;
		q%=mo;
	}
 
	cout<<p*pw(q,mo-2,mo)%mo<<endl;
}