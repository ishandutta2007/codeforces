#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

inline void add(int &x,int y){x+=y;if (x>=p) x-=p;}
int sum[N][3],C[3][3];
void trans(int *x,int *y)
{
	int z[3]={};
	for (int i=2;i>=0;i--)
	for (int j=i;j>=0;j--)
	add(z[i],1LL*x[j]*y[i-j]*C[i][j]%p);
	memcpy(x,z,sizeof(z));
}

signed main()
{
	for (int i=C[0][0]=1;i<3;i++)
	for (int j=C[i][0]=1;j<=i;j++)
	C[i][j]=C[i-1][j]+C[i-1][j-1];
	for (int i=0;i<N;i++) sum[i][0]=1;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),tmp[3]={2,x,1LL*x*x%p};
		trans(sum[x],tmp);
	}
	for (int j=1;j<N;j*=10)
	for (int i=N-1;i>=0;i--)
	if (i/j%10<9) trans(sum[i],sum[i+j]);
	for (int j=1;j<N;j*=10)
	for (int i=0;i<N;i++)
	if (i/j%10<9) add(sum[i][2],p-sum[i+j][2]);
	ll ans=0;
	for (int i=0;i<N;i++) ans^=1LL*i*sum[i][2];
	print(ans);
	
	return 0;
}