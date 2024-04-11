#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1010;
int n,d[M],col[M];

int query(int x)
{
	cout<<"? "<<x<<endl;
	int tmp;cin>>tmp;return tmp;
}

void solve()
{
	n=read();int tot=0;
	for (int i=1;i<=n;i++)d[i]=read(),col[i]=0;
	while(1)
	{
		int pos=-1;
		for (int i=1;i<=n;i++)if (!col[i]&&(pos==-1||d[i]>d[pos]))pos=i;
		if (pos==-1)break;
		tot++;vector<int>v;v.pb(pos);col[pos]=tot;
		for (int i=1;i<=d[pos];i++)
		{
			int x=query(pos);
			if (col[x])
			{
				for (auto y:v)col[y]=col[x];
				break;
			}
			v.pb(x),col[x]=tot;
		}
	}
	cout<<"!";
	for (int i=1;i<=n;i++)cout<<' '<<col[i];
	cout<<endl;
}

signed main()
{
	WT solve();
	return 0;
}