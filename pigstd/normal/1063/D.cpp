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

int n,l,r,k,len,ans=-1;

void work(int tmp,int L,int R)
{
	if (tmp!=0)ckmin(R,(k-len)/tmp),ckmax(L,(k-2*len-1)/tmp+1);
	else if (k-len<0||k-2*len>0)return;
	ckmin(R,(k+1+2*n-2*len)/(tmp+1)),ckmax(L,(k-len+n-1)/(1+tmp)+1);
	if (L<=R)ckmax(ans,R-n);
}

signed main()
{
	n=read(),l=read(),r=read(),k=read();
	if (r>=l)len=r-l+1;
	else len=n+r+1-l;
	for (int l=1,r=0;l<=k-1;l=r+1)
	{
		r=(k-1)/((k-1)/l);int tmp=(k-1)/l;
		// kk=k-tmp*x
		work(tmp,max(n,l),min(2*n,r));
	}
	work(0,max(n,k),2*n);
	cout<<ans<<'\n';
	return 0;
}