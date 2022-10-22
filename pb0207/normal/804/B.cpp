#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N=1e6+1e3+7,P=1e9+7;

int tmp,ans,n;

char s[N];

int main()
{
	scanf("%s",s);
	int n=strlen(s);
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]=='b')
			tmp++;
		if(s[i]=='a')
		{
			ans=(ans+tmp)%P;
			tmp=(tmp%P+tmp)%P;
		}
	}
	printf("%d",ans);
}