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

const int M=1e5+10;
int n,a,b,c,p[M],len;
char s[M];

void solve(int k)
{
	n=read(),a=read(),b=read(),c=read();cin>>s+1;
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	for (int i=1;i<=n;i++)
		if (s[i]==s[i-1])
		{
			if (s[i]=='0')cnt1++;
			else cnt2++;
		}
		else
		{
			if (s[i]=='0')cnt3++;
			else cnt4++;
		}
	if (cnt2==cnt1||cnt2==cnt1+1)
	{
		int ans=cnt1*a+cnt2*b;
		if (b>c&&cnt4!=0)ans+=(b-c)*min(cnt3,cnt4-1);
		printf("%lld\n",ans);
	}
	else if (cnt2<cnt1)
	{
		int ans=cnt2*b+(cnt2+1)*a;
		int len=0,cnt=0,F=1;
		for (int i=1;i<=n;i++)
		{
			if (s[i]=='0')cnt++;
			else 
			{
				if (cnt&&(!F||s[1]=='1'))p[++len]=cnt;
				cnt=0;F=0;
			}
		}
//		if (cnt)p[++len]=cnt;
		sort(p+1,p+1+len);int tot=0;
		for (int i=1;i<=len;i++)
			if (p[i]-1<=cnt2)cnt2-=p[i]-1,tot++;
			else break;
		if (b>c)ans+=(b-c)*tot;
		printf("%lld\n",ans);
	}
	else
	{
		int ans=cnt1*a+(cnt1+1)*b;
		if (b>c)ans+=(b-c)*min(cnt3,cnt2+cnt4-cnt1-2);
		printf("%lld\n",ans);
	}
}

signed main()
{
//	freopen("qwq.txt","r",stdin);
//	freopen("2.out","w",stdout);
	int TT=read();for (int i=1;i<=TT;i++) solve(i); 
	return 0;
}
/*
1
10 5 5 1
0011101011
*/