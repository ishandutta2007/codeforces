#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int t,n,len,fl;
char s[3000005];
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		fl=0;
		scanf("%d%s",&n,s+1);
		len=strlen(s+1);
		if(n<=len) fl=1;
		for(int i=1;i<=n;i++)
		{
			if(!fl&&s[i]=='2')
			{
				for(int ii=len+1,j=i+1;j<=len;ii++,j++)
					s[ii]=s[j];
				len+=(len-i);
				if(len>=n) fl=1;
			}
			else if(!fl&&s[i]=='3')
			{
				int plen=len;
				for(int ii=len+1,j=i+1;j<=len;ii++,j++)
					s[ii]=s[j];
				len+=(len-i);
				for(int ii=len+1,j=i+1;j<=plen;ii++,j++)
					s[ii]=s[j];
				len+=(plen-i);
				if(len>=n) fl=1;
			}
			else if(fl)
			{
				len=addmod(len+1ll*(s[i]-'1')*submod(len-i)%mod);
			}
			//printf("i=%d,len=%d,fl=%d\n",i,len,fl);
		}
		printf("%d\n",len);
	}
	return 0;
}