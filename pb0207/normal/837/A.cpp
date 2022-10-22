#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char s[201];

int n;

int main()
{
	cin>>n;
	int ans=0;
	while(n>0)
	{
		scanf("%s",s);
		n-=strlen(s);
		n--;
		int tot=0;
		for(int i=0;i<strlen(s);i++)
			if(s[i]>='A'&&s[i]<='Z')
				tot++;
		ans=max(ans,tot);
	}
	cout<<ans;
}