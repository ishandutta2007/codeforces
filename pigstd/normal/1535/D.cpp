#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
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

const int M=1e6+10;
int n,a[M],lson[M],rson[M],fa[M],f[M];
string s;
queue<int>q;

signed main()
{
	n=read();int len=(1<<n)-1;
	cin>>s;
	for (int i=1;i<=len;i++)
		if (s[i-1]=='0')a[i]=1;
		else if (s[i-1]=='1')a[i]=2;
		else a[i]=3;
	for (int i=len+1;i<=len*2+1;i++)f[i]=1;
	for (int i=1;i<=len+1;i++)
		q.push(i+len);int cnt=0;
	while(!q.empty())
	{
		int l=q.front();q.pop();
		if (q.empty())break;
		int r=q.front();q.pop();
		lson[++cnt]=l,rson[cnt]=r;
		if (a[cnt]==1)f[cnt]=f[l];
		if (a[cnt]==2)f[cnt]=f[r];
		if (a[cnt]==3)f[cnt]=f[l]+f[r];
		fa[l]=fa[r]=cnt;q.push(cnt);
	}//cout<<lson[1]<<' '<<rson[1]<<endl;
	int q=read();//cout<<cnt<<endl;
//	for (int i=1;i<=len;i++)cout<<fa[i]<<' ';puts("");
	while(q--)
	{
//		cout<<"qwq "<<f[8]<<endl; 
		int x=read();string p;cin>>p;//int ff=x==1;
		if (p=="0")a[x]=1,f[x]=f[lson[x]];
		else if (p=="1")a[x]=2,f[x]=f[rson[x]];
		else a[x]=3,f[x]=f[lson[x]]+f[rson[x]];
//		if (ff)
//		cout<<lson[x]<<' '<<rson[x]<<' '<<f[lson[x]]<<' '<<f[rson[x]]<<' '<<f[x]<<endl;
		while(x!=cnt)
		{
			x=fa[x];
			if (a[x]==1)f[x]=f[lson[x]];
			else if (a[x]==2)f[x]=f[rson[x]];
			else f[x]=f[lson[x]]+f[rson[x]];
		}
//		for (int i=1;i<=1;i++)
//			cout<<i<<' '<<f[i]<<endl;
		cout<<f[cnt]<<endl;
	}
	return 0;
}