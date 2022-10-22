#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N=1e6+1e3+7;

char s[N];

int a[N],n,k,posr[27],posl[27];

int main()
{
	cin>>n>>k;
	scanf("%s",s);
	for(int i=0;i<26;i++)
		posl[i]=0x7fffffff;
	memset(posr,-1,sizeof posr);
	for(int i=0;i<n;i++)
		posl[s[i]-'A']=min(i,posl[s[i]-'A']),posr[s[i]-'A']=max(i,posr[s[i]-'A']);
	for(int i=0;i<26;i++)
		if(posl[i]!=0x7fffffff&&posr[i]!=-1)
			a[posl[i]]+=1,a[posr[i]+1]-=1;
	for(int i=1;i<n;i++)
		a[i]+=a[i-1];
	for(int i=0;i<n;i++)
		if(a[i]>k)
		{
			printf("YES");
			return 0;
		}
	printf("NO");
}