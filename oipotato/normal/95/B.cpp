#include <cstdio>
#include <cstring>
using namespace std;
char n[100010],ans[100010];
int len,num1,num2;
int main()
{
	scanf("%s",n+1);
	len=strlen(n+1);
	if(len%2)
	{
		len++;
		for(int i=1;i<=len/2;i++)
		{
			ans[i]='4';
		}
		for(int i=1;i<=len/2;i++)
		{
			ans[i+len/2]='7';
		}
	}
	else
	{
		for(int i=1;i<=len;i++)
		{
			if(n[i]=='4'&&num1<len/2)
			{
				ans[i]='4';
				num1++;
			}
			else if((n[i]=='7'||num1==len/2&&n[i]<'7')&&num2<len/2)
			{
				ans[i]='7';
				num2++;
			}
			else if(n[i]<'4'&&num1<len/2)
			{
				ans[i]='4';
				num1++;
				for(int j=num1+1;j<=len/2;j++)
				{
					ans[i+j-num1]='4';
				}
				for(int j=num2+1;j<=len/2;j++)
				{
					ans[len/2+j]='7';
				}
				break;
			}
			else if(n[i]<'7'&&num2<len/2)
			{
				ans[i]='7';
				num2++;
				for(int j=num1+1;j<=len/2;j++)
				{
					ans[i+j-num1]='4';
				}
				for(int j=num2+1;j<=len/2;j++)
				{
					ans[len/2+j]='7';
				}
				break;
			}
			else
			{
				int pos=0;
				for(int j=i-1;j>=1;j--)
				{
					if(ans[j]=='4'&&num2<len/2)
					{
						ans[j]='7';
						num2++;
						num1--;
						pos=j;
						break;
					}
					else if(ans[j]=='7')
					{
						num2--;
					}
					else
					{
						num1--;
					}
				}
				if(pos)
				{
					for(int j=num1+1;j<=len/2;j++)
					{
						ans[pos+j-num1]='4';
					}
					for(int j=num2+1;j<=len/2;j++)
					{
						ans[j+len/2]='7';
					}
				}
				else
				{
					len+=2;
					for(int j=1;j<=len/2;j++)
					{
						ans[j]='4';
					}
					for(int j=1;j<=len/2;j++)
					{
						ans[j+len/2]='7';
					}
				}
				break;
			}
		}
	}
	puts(ans+1);
	return 0;
}