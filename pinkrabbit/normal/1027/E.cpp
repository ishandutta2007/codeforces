#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;
const int Mod=998244353;
int n,q,Ans;
int f[505][505];
void P(int&x,int y){x-=(x+=y)>=Mod?Mod:0;}
int main(){
	scanf("%d%d",&n,&q); --q;
	if(!q) return 0*puts("0");
	F(k,1,n){
		f[k][0]=1;
		F(i,1,n) F(j,1,k) if(i>=j) P(f[k][i],f[k][i-j]);
	}
	F(i,1,n){
		int D=(f[i][n]-f[i-1][n]+Mod)%Mod;
		int j=q/i;
		if(j>n) j=n;
		Ans=(Ans+(LL)D*f[j][n])%Mod;
	} printf("%d",Ans*2%Mod);
	return 0;
} // Luogu_Loves_Judging