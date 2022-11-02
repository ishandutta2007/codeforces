#include<cstdio>
using namespace std;
long long move[2][61];
int q;
void modify(int typ,long long x,long long k,int level)
{
	if((1ll<<level)-1<x)modify(typ,x,k,level+1);
	else
	{
		long long len=1ll<<(level-1);
		move[typ][level]=(move[typ][level]+k%len+len)%len;
	}
}
long long find_pos(long long x,int level)
{
	if((1ll<<level)-1<x)return find_pos(x,level+1);
	else
	{
		long long len=1ll<<(level-1);
		return (move[1][level]+x)%len+len;
	}
}
void print(long long x,int level)
{
	if((1ll<<(level-1))>x)print(x,level-1);
	else
	{
		long long len=1ll<<(level-1);
		printf("%lld",(x-move[1][level]+len)%len+len);
		if(level==1)puts("");
		else
		{
			putchar(' ');
			print(((x+move[0][level])%len+len)>>1,level-1);
		}
	}
}
int main()
{
	scanf("%d",&q);
	for(;q--;)
	{
		int opt;
		long long x,k;
		scanf("%d",&opt);
		if(opt==3)
		{
			scanf("%lld",&x);
			print(find_pos(x,1),60);
		}
		else
		{
			scanf("%lld%lld",&x,&k);
			modify(2-opt,x,k,1);
		}
	}
	return 0;
}