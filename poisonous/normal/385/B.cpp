#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
char a[5010];
int main()
{
	scanf("%s",a);
	int n,m,ans=0;
	for(n=0;n<strlen(a);n++)
	{
		bool b=0;
		for(m=n+3;m<strlen(a);m++)
		{
			if(a[m-3]=='b'&&a[m-2]=='e'&&a[m-1]=='a'&&a[m]=='r')
				b=1;
			if(b)
				ans++;
		}
	}
	cout<<ans;
}