#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n;
int f[200001],i2,s[200001];
inline int add(int x,int y){
	return x+y<mod?x+y:x+y-mod;
}
inline int power(int a,int n){
	int tp=1;
	while(n){
		if(n&1) tp=1ll*tp*a%mod;
		a=1ll*a*a%mod,n>>=1;
	}
	return tp;
}
int main(){
	cin>>n;
	f[0]=s[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=s[i&1^1];
		s[i&1]=add(s[i&1],f[i]);
	}
	cout<<1ll*f[n]*power(power(2,n),mod-2)%mod;
}