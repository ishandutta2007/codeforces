// By: Little09
// Problem: CF718C Sasha and Array
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF718C
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1000000007;
struct Matrix 
{
    ll a[3][3];
    Matrix () {memset(a, 0, sizeof (a));}
    void init() 
    { 
    	a[1][1]=a[2][2]=1,a[1][2]=a[2][1]=0; 
    }
    bool binit() 
    { 
    	return a[1][1]==1&&a[2][2]==1&&a[1][2]== 0&&a[2][1]==0; 
    }
    Matrix operator + (const Matrix b) 
    {
        Matrix res;
        for (int i=1;i<=2;i++)
        {
        	for (int j=1;j<=2;j++)
        	{
        		res.a[i][j]=(a[i][j]+b.a[i][j])%mod;
        	}
        }
        return res;
    }
    Matrix operator * (const Matrix b) 
    {
        Matrix res;
        for (int k=1;k<=2;k++)
        {
        	for (int i=1;i<=2;i++)
        	{
        		for (int j=1;j<=2;j++)
        		{
        			res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j])%mod;
        		}
        	}
        }
        return res;
    }
    Matrix operator ^ (int b) 
    { 
        Matrix res, base;
        res.init();
        for (int i=1;i<=2;i++) for (int j=1;j<=2;j++) base.a[i][j]=a[i][j];
        while (b) 
        {
            if (b&1) res=res*base;
            base=base*base;
            b>>=1;
        }
        return res;
    }
}base,ans;
const int N=100005;
int a[N];
int n,m; 
Matrix sum[N*4],add[N*4];
void push_up(int u)
{
	sum[u]=sum[u*2]+sum[u*2+1];
}
void push_down(int u)
{
	if (add[u].binit()==0) 
	{
		add[u*2]=add[u*2]*add[u];
		add[u*2+1]=add[u*2+1]*add[u];
		sum[u*2]=sum[u*2]*add[u];
		sum[u*2+1]=sum[u*2+1]*add[u];
		add[u].init();
	}
}
void build(int u,int l,int r)
{
	if (l==r)
	{
		if (a[l]==1) sum[u].a[1][1]=1;
		else sum[u]=ans*(base^(a[l]-2));
		add[u].init();
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	add[u].init();
	push_up(u);
}
ll ask(int u,int L,int R,int l,int r)
{
	if (l<=L&&R<=r) return sum[u].a[1][1];
	int mid=(L+R)>>1;
	push_down(u);
	ll res=0;
	if (l<=mid) res=(res+ask(u*2,L,mid,l,r))%mod;
	if (mid<r) res=(res+ask(u*2+1,mid+1,R,l,r))%mod;
	return res;
}
void change(int u,int L,int R,int l,int r,Matrix k)
{
	if (l<=L&&R<=r) 
	{
		sum[u]=sum[u]*k;
		add[u]=add[u]*k;
		return;
	}
	int mid=(L+R)>>1;
	push_down(u);
	if (l<=mid) change(u*2,L,mid,l,r,k);
	if (mid<r) change(u*2+1,mid+1,R,l,r,k);
	push_up(u);
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}

int main()
{
	base.a[1][1]=base.a[1][2]=base.a[2][1]=1;
	ans.a[1][1]=ans.a[1][2]=1;
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int tp=read(),l=read(),r=read();
		if (tp==1)
		{
			int k=read();
			change(1,1,n,l,r,base^k);
		}
		else printf("%lld\n",ask(1,1,n,l,r)%mod);
	}
	return 0;
}