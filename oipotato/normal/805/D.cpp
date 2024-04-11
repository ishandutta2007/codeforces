#include<cstdio>
using namespace std;
const int MOD=1E9+7;
int tans[1000010],mi[1000010],tmp,ans;
char ch;
int main()
{
	mi[0]=1;
	for(int i=1;i<=1000000;i++)mi[i]=mi[i-1]*2%MOD;
	tans[0]=1;
	for(int i=1;i<=1000000;i++)tans[i]=(tans[i-1]+mi[i])%MOD;
	for(ch=getchar();ch=='a'||ch=='b';ch=getchar())
	if(ch=='a')tmp++;
	else ans=(ans+tans[tmp-1])%MOD;
	printf("%d",ans);
	return 0;
}