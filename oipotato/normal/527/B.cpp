#include<cstdio>
using namespace std;
int n,S[200010],T[200010],need[30][30],ans;
int main()
{
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)S[i]=getchar()-'a';getchar();
	for(int i=1;i<=n;i++)T[i]=getchar()-'a';
	for(int i=1;i<=n;i++)ans+=S[i]!=T[i];
	for(int i=1;i<=n;i++)if(S[i]!=T[i])need[S[i]][T[i]]=i;
	for(int i=1;i<=n;i++)
	if(S[i]!=T[i])
	if(need[T[i]][S[i]]){printf("%d\n%d %d",ans-2,i,need[T[i]][S[i]]);return 0;}
	for(int i=1;i<=n;i++)
	if(S[i]!=T[i])
	for(int j=0;j<26;j++)if(need[T[i]][j]){printf("%d\n%d %d",ans-1,i,need[T[i]][j]);return 0;}
	printf("%d\n-1 -1",ans);
	return 0;
}