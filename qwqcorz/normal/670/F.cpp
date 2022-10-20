#include<bits/stdc++.h>
using namespace std;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int cnt[10],now[10];
string ans,a;
vector<int>length(int x)
{
	vector<int>ret(0);
	do ret.push_back(x%10),x/=10;while (x);
	return ret;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	ans="a";
	cin>>a;
	int n=a.length();
	for (char i:a) cnt[i-'0']++;
	cin>>a;
	for (int k=1;k<=6;k++)
	if ((int)length(n-k).size()==k)
	{
		int len=n-k;
		vector<int>l=length(len);
		memcpy(now,cnt,sizeof(now));
		for (int i:l) now[i]--;
		for (char i:a) now[i-'0']--;
		
		bool flag=1;
		for (int i=0;i<=9;i++) if (now[i]<0) flag=0;
		if (!flag) continue;
		
		string x="",y="",z="";
		int tmp=0;
		for (int i=9;i>=1;i--) if (now[i]) tmp=i;
		if (tmp)
		{
			if (a[0]>'0')
			{
				z+=a;
				for (int i=0;i<=9;i++)
				for (int j=1;j<=now[i];j++) z+=i+'0';
			}
			else z="a";
			x=y=tmp+'0';
			now[tmp]--;
			for (int i=0;i<=9;i++)
			{
				if (a[0]-'0'==i) x+=a;
				while (now[i]--) x+=i+'0',y+=i+'0';
				if (a[0]-'0'==i) y+=a;
			}
			ans=min(ans,min(min(x,y),z));
		}
		else
		{
			x=a;
			while (now[0]--) x+='0';
			ans=min(ans,x);
		}
	}
	cout<<ans;
	
	return 0;
}