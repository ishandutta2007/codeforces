#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int N=1e5+1e3+7;

int can[N],n,len,pos,lenq;

char ok[N],s[N],qs[N];

int main()
{
	scanf("%s",ok);
	for(int i=0;i<strlen(ok);i++)
		can[ok[i]]=true;
	scanf("%s",s);
	pos=-1;
	len=strlen(s);
	scanf("%d",&n);
	for(int i=0;i<len;i++)
		if(s[i]=='*')
		{
			pos=i;
			break;
		}
	while(n--)
	{
		scanf("%s",qs);
		if(pos==-1)
		{
			lenq=strlen(qs);
			if(lenq!=len)
				cout<<"NO"<<endl;
			else
			{
				for(int i=0;i<len;i++)
					if(s[i]!=qs[i]&&(s[i]!='?'||(s[i]=='?'&&!can[qs[i]])))
					{
						cout<<"NO"<<endl;
						goto ddd;
					}
				cout<<"YES"<<endl;
				ddd:;
			}
		}
		else
		{
			lenq=strlen(qs);
			bool flag=true;
			if(len-1>lenq)
			{
				flag=false;
			}
			for(int i=0;i<pos;i++)
				if(s[i]!=qs[i]&&(s[i]!='?'||(s[i]=='?'&&!can[qs[i]])))
					{
						flag=false;
						break;
					}
			int i=len-1,j=lenq-1;
			while(i>pos)
			{
				if(s[i]!=qs[j]&&(s[i]!='?'||(s[i]=='?'&&!can[qs[j]])))
					{
						flag=false;
						break;
					}
				i--,j--;
			}
			int res=len-pos-1;
			for(int i=pos;i<lenq-res;i++)
				if(can[qs[i]])
					flag=false;
			if(flag)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
}