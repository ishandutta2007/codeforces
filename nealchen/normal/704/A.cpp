//zcd
#include<stdio.h>
int n,q,tot,max3=1,ans,s[300010],f[300010],del[300010];
int main()
{
    scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
	{
		int o,x;
		scanf("%d%d",&o,&x);
		if(o==1)
		{
			f[++tot]=x;
			s[x]++;
			ans++;
		}
		if(o==2)
		{
			ans-=s[x];
			s[x]=0;
			del[x]=tot;
		}
		if(o==3&&x>=max3)
		{
			for(int j=max3;j<=x;j++) 
			{
				if(del[f[j]]<j)
				{
				    s[f[j]]--;
					ans--;
				}
			}
			max3=x+1;
		}
		printf("%d\n",ans);
	}
    return 0;
}