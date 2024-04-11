#include<bits/stdc++.h>
#define int long long
#define pb push_back
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

const int M=2e5+10;
int n,a1[M],a2[M],ans[M],sum,cnt,now1,noww;

int find(int x)
{
	if (sum&1)return noww-x+1;
	else return noww+x-1;
}

void opt(int x)
{
	noww=find(x);sum++;
}

signed main()
{
	WT
	{
		n=read();cnt=0;sum=0,noww=1;
		string s1,s2;cin>>s1>>s2;
		for (int i=1;i<=n;i++)
			a1[i]=s1[i-1]-'0',a2[i]=s2[i-1]-'0';
		now1=a1[1];
		for (int i=n;i>=2;i--)
		{
			if ((a1[find(i)]^(sum&1))!=a2[i])
			{
				if ((a1[find(i)]^(sum&1))!=(now1^(sum&1)))
					ans[++cnt]=1,now1^=1;
				ans[++cnt]=i;opt(i);
			}
		}
		if ((now1^(sum&1))!=a2[1])ans[++cnt]=1;
		cout<<cnt<<' ';
		for (int i=1;i<=cnt;i++)cout<<ans[i]<<' ';
		puts("");
	}
}