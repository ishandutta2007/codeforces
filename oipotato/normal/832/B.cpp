#include <cstdio>
#include <cstring>
using namespace std;
char st1[100010],st[100010];
int len1,len,n,pos=-1;
bool flag,good[1010];
int main()
{
	scanf("%s",st1);
	len1=strlen(st1);
	for(int i=0;i<len1;i++)
		good[st1[i]]=1;
	scanf("%s",st1);
	len1=strlen(st1);
	for(int i=0;i<len1;i++)
		if(st1[i]=='*')
			pos=i;
	scanf("%d\n",&n);
	for(;n--;)
	{
		scanf("%s",st);
		len=strlen(st);
		flag=1;
		if(pos==-1)
		{
			for(int i=0;i<len1;i++)
			{
				if(len!=len1)
				{
					flag=0;
					break;
				}
				if(st1[i]=='?'&&good[st[i]])continue;
				if(st[i]!=st1[i])
				{
					flag=0;
					break;
				}
			}
		}
		else if(len>=len1-1)
		{
			for(int i=0;i<pos;i++)
			{
				if(st1[i]=='?'&&good[st[i]])continue;
				if(st[i]!=st1[i])
				{
					flag=0;
					break;
				}
			}
			for(int i=pos+1;i<len1;i++)
			{
				if(st1[i]=='?'&&good[st[len-len1+i]])continue;
				if(st[len-len1+i]!=st1[i])
				{
					flag=0;
					break;
				}
			}
			for(int i=pos;i<len-len1+pos+1;i++)
				if(good[st[i]])
				{
					flag=0;
					break;
				}
		}
		else
			flag=0;
		printf(flag?"YES\n":"NO\n");
	}
	return 0;
}