#include<cstdio>
#include<cstring>

int n,k,cnt,num;
char s[300001];

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	cnt=num=0;
	for (int i=1; i<=n; i++)
		if (s[i]=='(') {if (num<k/2) putchar('('),num++,cnt++;}
		else {if (cnt>0) putchar(')'),cnt--;}
	putchar('\n');
	return 0;
}