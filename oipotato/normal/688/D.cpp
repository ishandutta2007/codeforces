#include<cstdio>
using namespace std;
int n,k,c[1000010],prime[1000010],a[30],len,tot;
bool check[1000010];
int main()
{
	//freopen("4.in","r",stdin);
	//freopen("4.out","w",stdout);
	scanf("%d%d",&n,&k);for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=2;i<=k;i++)
	{
		if(!check[i])prime[++tot]=i;
		for(int j=1;j<=tot;j++)
		{
			if((long long)prime[j]*i>k)break;
			check[prime[j]*i]=1;
			if(!(i%prime[j]))break;
		}
	}
	for(int i=1;i<=tot;i++)
	{
		int mul=1;
		for(;!(k%prime[i]);){mul*=prime[i];k/=prime[i];}
		a[++len]=mul;
	}
	for(int i=1;i<=len;i++)
	{
		bool bo=0;for(int j=1;j<=n;j++)if(!(c[j]%a[i])){bo=1;break;}
		if(!bo){printf("No");return 0;}
	}
	printf("Yes");
	return 0;
}