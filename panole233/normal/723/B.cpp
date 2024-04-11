#include<cstdio>
#include<cstring>

char s[1001];
int st,o,max1,max2,n;

int main()
{
	scanf("%d",&n);
	scanf("%s",&s);
	st=0; max1=max2=o=0;
	for (int i=0; i<n; i++)
	{
		if (s[i]=='(') st++;
		else if (s[i]==')') st--; else
		if (s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
		{
			if (st>0) 
			{
				if (s[i-1]=='('||s[i-1]=='_'||s[i-1]==')') max2++;
			}
			else 
			{
				if (i==0||s[i-1]=='_'||s[i-1]==')') 
				{
					if (max1<o) max1=o;
					o=1;
				}
				else o++;
			}
		}
	}
	if (max1<o) max1=o;
	printf("%d %d",max1,max2);
	return 0;
}