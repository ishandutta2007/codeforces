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

const int M=(1<<18)+10;
int n,rk[M];
char s[M];
pii a[M];

signed main()
{
	n=read();int len=(1<<n);
	cin>>s;
	for (int i=0;i<len;i++)rk[i]=s[i]-'a'+1;
	for (int i=0;i<n;i++)
	{
//		for (int j=0;j<len;j++)cout<<rk[j]<<' ';puts("");
		for (int j=0;j<len;j++)
			a[j]=mp(rk[j]*(len+1)+rk[j^(1<<i)],j);
		sort(a,a+len);
		int cnt=0;
		for (int j=0;j<len;j++)
		{
			if (j==0||a[j].x!=a[j-1].x)cnt++;
			rk[a[j].y]=cnt;
		}
	}
//	for (int j=0;j<len;j++)cout<<rk[j]<<' ';
	int x=-1;
	for (int i=0;i<len;i++)
		if (rk[i]==1)x=i;
	for (int i=0;i<len;i++)
		cout<<s[i^x];
	return 0;
}