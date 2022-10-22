#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10; 
const int inf=1e18;
int f[2][M],n,k,p,q[M];

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)f[0][i]=inf;
	while(k--)
	{
		int l=read(),r=read();
		p^=1;
    	memcpy(f[p],f[p^1],sizeof f[p]);
		int tl=1,tr=0;
		for (int i=0;i<=min(n,r);i++)
		{
			while(tl<=tr&&f[p^1][i]<=f[p^1][q[tr]])tr--;
			while(tl<=tr&&q[tl]<i-r+l)tl++;
			q[++tr]=i; 
			f[p][i]=min(f[p][i],f[p^1][q[tl]]+2);
		}tl=1,tr=0;
		for (int i=r;i>=0;i--)
		{
			while(tl<=tr&&f[p^1][r-i]<=f[p^1][q[tr]])tr--;
			while(tl<=tr&&q[tl]<l-i)tl++;
			q[++tr]=r-i;
			f[p][i]=min(f[p][i],f[p^1][q[tl]]+1);
		}
	}
	if (f[p][n]!=inf)cout<<"Full"<<endl<<f[p][n]<<endl;
	else cout<<"Hungry"<<endl;
	return 0;
}