#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char s[N];
int dp[N],q[N];

signed main()
{
	int m=read();
	scanf("%s",s+1);
	int n=strlen(s+1);
	s[0]=s[n+1]=0;
	char up=0;
	for (char c='a';c<='z';c++)
	{
		int lst=0,flag=1;
		for (int i=1;i<=n+1;i++)
		if (s[i]<=c)
		{
			if (i-lst-1>=m) flag=0;
			lst=i;
		}
		if (flag){up=c;break;}
	}
	int h=0,t=0;
	for (int i=1;i<=n+1;i++)
	if (s[i]<=up)
	{
		while (i-q[h]-1>=m) h++;
		dp[i]=dp[q[h]]+1;
		if (s[i]<up) h=t+1;
		q[++t]=i;
	}
	int ans=dp[n+1]-1;
	string res="";
	for (char c='a';c<='z';c++)
	for (int i=1;i<=n;i++) if (s[i]==c&&ans) res+=s[i],ans--;
	cout<<res<<endl;
	
	return 0;
}