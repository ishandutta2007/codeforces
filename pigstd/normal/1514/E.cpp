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
	if (f)exit(0);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=110;
int n,a[M],cnt,ans[M][M],f[M];

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

int check(int x,int y)
{
	if (y<0)return 0;assert(x>y);
	cout<<2<<' '<<a[x]<<' '<<y+1<<' ';
	for (int i=0;i<=y;i++)cout<<a[i]<<' ';cout<<endl;
	return read();
}

signed main()
{
	WT
	{
		n=read();
		for (int i=0;i<n;i++)f[i]=i,a[i]=0;
		for (int i=0;i<n;i++)for (int j=0;j<n;j++)ans[i][j]=0;
		for (int i=1;i<n;i++)
		{
			cout<<"1 "<<i<<' '<<a[0]<<endl;
			if (read())
			{
				for (int j=i;j>=1;j--)a[j]=a[j-1];
				a[0]=i;continue;
			}
			cout<<"1 "<<a[i-1]<<' '<<i<<endl;
			if (read()){a[i]=i;continue;}
			int tl=0,tr=i-2,p=i-2;
			while(tl<=tr)
			{
				int Mid=(tl+tr)>>1;
				cout<<1<<' '<<a[Mid]<<' '<<i<<endl;
				if (read())tl=Mid+1,p=Mid;
				else tr=Mid-1;
			}
			//0...p i p+1...
			for (int j=i;j>p+1;j--)a[j]=a[j-1];a[p+1]=i;
		}int l=n-1;
		for (int i=n-1;i>=0;i--)
		{
			if (l==i)l--;
			while(check(i,l))f[find(a[i])]=find(a[l]),l--;
		}
		for (int i=0;i<n;i++)
			for (int j=i;j<n;j++)ans[a[i]][a[j]]=1;
		cout<<3<<endl;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
				if (find(i)==find(j))cout<<1;
				else cout<<ans[i][j];
			cout<<endl;
		}read();
	}
	return 0;
}
// tm  1/-1 
//