#include <cstdio>
#include <cstring>

long long n,nn,s,er[62],p,po;
int q,x;

int main()
{
	scanf("%I64d",&n);
	scanf("%d",&q); nn=(n-1)*2ll;
	x=0; er[0]=1;
	for (int i=1; i<=61; i++) er[i]=er[i-1]*(2ll);
	for (int i=0; i<=61; i++)
		if (nn>=er[i]) nn-=er[i],x=i;
		else break;
	while (q--)
	{
		scanf("%I64d",&s);
		if (n==2) {if (s==1) printf("1\n"); else printf("2\n"); continue;}
		if (s&1) {printf("%I64d\n",(s+1)/2); continue;}
		p=er[x]; po=nn+p;
		if (s<=nn) s+=p+1-s/2+(nn-1)/2;
		p/=2;
		while (p)
		{
			if (s<=po)
			{
				if ((po-s+1)%2==1) break;
				s+=(po-s+1)/2+p;
			}
			po+=p; p/=2;
		}
		printf("%I64d\n",s/2+1);
	}
	return 0;
}