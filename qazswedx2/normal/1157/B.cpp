#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,f[1005],fl=0;
char s[1000005];
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=9;i++)
		scanf("%d",&f[i]);
	for(int i=1;i<=n;i++)
	{
		int nw=s[i]-'0';
		if(f[nw]>nw&&fl==0)
			fl=1,s[i]=f[nw]+'0';
		else if(f[nw]<nw&&fl==1)
			break;
		else if(fl==1)
			s[i]=f[nw]+'0';
	}
	printf("%s",s+1);
	return 0;
}