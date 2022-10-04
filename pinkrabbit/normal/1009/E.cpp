#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define ll long long
#define Mod 998244353

int n;
int a[1000001];
int p[1000001];

int main(){
	scanf("%d",&n);
	p[0]=1;
	F(i,1,n) p[i]=p[i-1]*2ll%Mod;
	F(i,1,n) scanf("%d",a+i);
	int Ans=0;
	F(i,1,n)
		Ans=(Ans+(ll)a[i]*((ll)(n-i)*p[n-i-1]%Mod+p[n-i])%Mod)%Mod;
	printf("%d",Ans);
	return 0;
}