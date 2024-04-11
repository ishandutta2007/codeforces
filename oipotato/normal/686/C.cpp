#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,ans,len1,len2,max1,max2,a[110],b[110],tmp[110];
bool use[10];
void dfs2(int k,bool f)
{
	if(k==len2){ans++;return;}
	if(!f){for(int i=0;i<7;i++)if(!use[i]){use[i]=1;dfs2(k+1,0);use[i]=0;}}
	else
	{
		for(int i=0;i<b[k];i++)if(!use[i]){use[i]=1;dfs2(k+1,0);use[i]=0;}
		if(!use[b[k]]){use[b[k]]=1;dfs2(k+1,1);use[b[k]]=0;}
	}
}
void dfs1(int k,bool f)
{
	if(k==len1)
	{
		for(int i=0;i<max2;i++)if(!use[i]){use[i]=1;dfs2(1,0);use[i]=0;}
		if(!use[max2]){use[max2]=1;dfs2(1,1);use[max2]=0;}
		return;
	}
	if(!f){for(int i=0;i<7;i++)if(!use[i]){use[i]=1;dfs1(k+1,0);use[i]=0;}}
	else
	{
		for(int i=0;i<a[k];i++)if(!use[i]){use[i]=1;dfs1(k+1,0);use[i]=0;}
		if(!use[a[k]]){use[a[k]]=1;dfs1(k+1,1);use[a[k]]=0;}
	}
}
int main()
{
	//freopen("3.in","r",stdin);
	//freopen("3.out","w",stdout);
	scanf("%d%d",&n,&m);n--;m--;if(!n)len1=1;if(!m)len2=1;
	for(;n;tmp[++len1]=n%7,n/=7)if(n<7)max1=n;
	for(int i=2;i<=len1;i++)a[i-1]=tmp[len1-i+1];
	for(;m;tmp[++len2]=m%7,m/=7)if(m<7)max2=m;
	for(int i=2;i<=len2;i++)b[i-1]=tmp[len2-i+1];
	for(int i=0;i<max1;i++){use[i]=1;dfs1(1,0);use[i]=0;}
	use[max1]=1;dfs1(1,1);
	printf("%d",ans);
	return 0;
}