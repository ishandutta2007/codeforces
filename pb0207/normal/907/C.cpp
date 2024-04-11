#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,cer;

char op[3],s[N];

bool pos[N],no[N],flag=1,wc[N],ch[N],tong[N];

bool chk()
{
	int cnt=0;
	for(int i=0;i<26;i++)
		cnt+=(pos[i]!=0&&(wc[i]&&!ch[i]));
	return cnt>1;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<26;i++)
		pos[i]=1,wc[i]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		flag&=chk();
		scanf("%s",op);
		scanf("%s",s);
		if(op[0]=='!')
		{
			if(!flag)
				ans++;
			int len=strlen(s);
			for(int j=0;j<26;j++)
				tong[j]=0;
			for(int j=0;j<len;j++)
				tong[s[j]-'a']=1;
			for(int j=0;j<26;j++)
				if(!tong[j])
					wc[j]=0;
		}
		if(op[0]=='.')
		{
			int len=strlen(s);
			for(int j=0;j<len;j++)
				pos[s[j]-'a']=0;
		}
		if(op[0]=='?')
		{
			if(((!flag))&&i!=n)
				ans++;
			if(i!=n)
				pos[s[0]-'a']=0;
			ch[s[0]-'a']=true;
		}
	}
	printf("%d",ans);
}