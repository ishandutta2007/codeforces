#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

int ans,a,b;
map<int,int>T; 

signed main()
{
	a=read(),b=read(); 
	int len=a+b;
	for (int t=1;t<=sqrt(len);t++)
	{
		int R=len/t,L=len/(t+1)+1;T[t]=1;
		if (R<L)continue;
		if (a/t<(a-1)/(t+1)+1||b/t<(b-1)/(t+1)+1)continue;
		ckmin(R,a/t+b/t),
		ckmax(L,(a-1)/(t+1)+(b-1)/(t+1)+2);
		ans+=max(R-L+1,0ll);
	}
	for (int i=1;i<=sqrt(len);i++)
	{
		int t=len/i,L=i,R=i;
		if (T[t])continue;T[t]=1;
		if (a/t>(a-1)/(t+1)+1||b/t>(b-1)/(t+1)+1)continue;
		ckmin(R,a/t+b/t),
		ckmax(L,(a-1)/(t+1)+(b-1)/(t+1)+2);
		ans+=max(R-L+1,0ll);
	}
	cout<<ans<<'\n';
	return 0;
}