#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int GCD(int x,int y){return y==0?x:GCD(y,x%y);}
int divisor[100005],cnt,a,b,n,low,high,gcd;
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	gcd=GCD(a,b);
	for(int i=1;i*i<=gcd;i++)
		if(gcd%i==0)
		{
			divisor[cnt++]=i;
			if(i*i!=gcd)
				divisor[cnt++]=gcd/i;
		}
	sort(divisor,divisor+cnt);
	while(n--)
	{
		scanf("%d%d",&low,&high);
		int tmp=*(upper_bound(divisor,divisor+cnt,high)-1);
		if(tmp<low)
			puts("-1");
		else
			printf("%d\n",tmp);
	}
	return 0;
}