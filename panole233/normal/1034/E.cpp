#include<bits/stdc++.h>
using namespace std;

const int N=(1<<21);
unsigned long long fa[N],F[N],FF,MO;
int n,a[N],x,y,t[100],A[N];
char s[3000000];

int bc(int x) {int ans=0; while (x) x-=(x&-x),ans++; return ans;}

void FWT()
{
	for (int i=0; i<(1<<n)-1; i++) F[i]=(1ull*A[i])<<(bc(i)*3);
	F[(1<<n)-1]=0;
	for (int i=2; i<=(1<<n); i<<=1)
		for (int j=0; j<(1<<n); j+=i)
			for (int k=j; k<j+(i>>1); k++) F[k+(i>>1)]=(F[k+(i>>1)]+F[k])&MO;
}

void mul(unsigned long long &a,unsigned long long b)
{
	for (int i=0; i<3*n; i++) t[i]=(a>>i&1);
	a=0; for (int i=0; i<3*n; i++) if (t[i]) a+=((b<<i)&MO),a&=MO;
}

void UFWT()
{
	for (int i=2; i<=(1<<n); i<<=1)
		for (int j=0; j<(1<<n); j+=i)
			for (int k=j; k<j+(i>>1); k++) 
				F[k+(i>>1)]=(F[k+(i>>1)]+FF-F[k])&MO;
}

int main()
{
	scanf("%d",&n); FF=MO=0;
	for (int i=0; i<n; i++) FF+=(1ull<<(i*3+2)),MO+=(3ull<<(i*3));
	scanf("%s",s);
	for (int i=0; i<(1<<n); i++) A[i]=a[i]=s[i]-'0';
	FWT(); for (int i=0; i<(1<<n); i++) fa[i]=F[i];
	scanf("%s",s);
	for (int i=0; i<(1<<n); i++) A[i]=s[i]-'0';
	int ans=0; for (int i=0; i<(1<<n); i++) ans=(ans+a[i]*A[i^((1<<n)-1)])&3;
	FWT(); for (int i=0; i<(1<<n); i++) mul(F[i],fa[i]);
	UFWT(); for (int i=0; i<(1<<n)-1; i++) putchar('0'+(F[i]>>(3*bc(i))&7));
	putchar(ans+'0');
	return 0;
}