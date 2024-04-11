#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e3+10;
int n,m,a[M][M],q,res;

int work(int x,int y)
{
	int res=-1;int x1=0,x2=0,nowx=x,nowy=y;
	for (int i=1;;i++)
	{
		if (i&1)nowx++;else nowy++; 
		if (nowy>m||nowx>n||a[nowx][nowy])break;
		x1++; 
	}nowx=x,nowy=y;
	for (int i=1;;i++)
	{
		if (i&1)nowy--;else nowx--;
		if (nowy<1||nowx<1||a[nowx][nowy])break;
		x2++;
	}res+=(x1+1)*(x2+1);
	nowx=x,nowy=y,x1=x2=0;
	for (int i=1;;i++)
	{
		if (i&1)nowy++;else nowx++; 
		if (nowy>m||nowx>n||a[nowx][nowy])break;
		x1++; 
	}nowx=x,nowy=y;
	for (int i=1;;i++)
	{
		if (i&1)nowx--;else nowy--;
		if (nowy<1||nowx<1||a[nowx][nowy])break;
		x2++;
	}res+=(x1+1)*(x2+1);
	return res;
}

signed main()
{
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			res+=min(2*i-1,(m-j)*2)+min(2*(i-1),(m-j)*2+1)+1;
//	cout<<res<<endl;
	while(q--)
	{
		int x=read(),y=read();
		if (a[x][y]==1)a[x][y]=0,res+=work(x,y);
		else res-=work(x,y),a[x][y]=1;
		cout<<res<<endl;
	}
	return 0;
}