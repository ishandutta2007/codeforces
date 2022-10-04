#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int Min(int a,int b){return a<b?a:b;}
inline int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
int n,m,col[200005],k[200005],num[200005],j,i=1,ans=200005,cha;
int main()
{
	n=read();m=read();
	for(i=1;i<=n;i++) col[i]=read(),num[col[i]]++;
	for(i=1;i<=m;i++) k[i]=read();
	for(int s=1;s<=m;s++){if(num[s]<k[s]){printf("-1");return 0;}}
	for(j=n;j>=2;j--){if(num[col[j]]==k[col[j]]) break;num[col[j]]--;}
	for(int s=1;s<=m;s++) cha+=num[s]-k[s];
	i=1;
	for(;j<=n;j++)
	{
		while(num[col[i]]>k[col[i]]) num[col[i]]--,i++,cha--;
		ans=Min(ans,cha);
		num[col[j+1]]++;cha++;
	}
	printf("%d",ans);
	return 0;
}