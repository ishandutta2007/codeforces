#include<cstdio>

int gcd(int a,int b) {return (!b)?a:gcd(b,a%b);}

int main()
{
	int n,m,k,cnt=0,x;
	scanf("%d%d%d",&n,&m,&k);
	while (!(k&1)) k>>=1,cnt++;
	x=gcd(n,k); n/=x; k/=x;
	x=gcd(m,k); m/=x; k/=x;
	if (k!=1) {printf("NO\n"); return 0;}
	if (cnt==0)
	{
		if (x==1) n<<=1; else m<<=1;
		printf("YES\n%d %d\n%d %d\n%d %d\n",0,0,n,0,0,m);
		return 0;
	}
	cnt--; k=2;
	while ((!(n&1))&&cnt) cnt--,n>>=1;
	while ((!(m&1))&&cnt) cnt--,m>>=1;
	if (cnt) printf("NO\n"); else 
	{
		printf("YES\n");
		printf("%d %d\n%d %d\n%d %d\n",0,0,n,0,0,m);
	}
	return 0;
}