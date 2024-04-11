#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int n,f[1000005][4];
char s[1000005];
bool checka(int x)
{
	return s[x]=='a'||s[x]=='?';
}
bool checkb(int x)
{
	return s[x]=='b'||s[x]=='?';
}
bool checkc(int x)
{
	return s[x]=='c'||s[x]=='?';
}
int main()
{
	scanf("%d%s",&n,s+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		int mul=1;
		if(s[i]=='?') mul=3;
		f[i][0]=1ll*mul*f[i-1][0]%mod;
		f[i][1]=1ll*mul*f[i-1][1]%mod;
		f[i][2]=1ll*mul*f[i-1][2]%mod;
		f[i][3]=1ll*mul*f[i-1][3]%mod;
		if(checka(i)) f[i][1]=(f[i][1]+f[i-1][0])%mod;
		if(checkb(i)) f[i][2]=(f[i][2]+f[i-1][1])%mod;
		if(checkc(i)) f[i][3]=(f[i][3]+f[i-1][2])%mod;
	}
	printf("%d\n",f[n][3]);
	return 0;
}