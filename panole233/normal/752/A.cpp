#include<cstdio>
#include<cstring>

int n,m,k,l,d,lr,kk,o;

int main()
{
	scanf("%d%d%d",&n,&m,&k); kk=k; k%=(2*m);
	if (k==0) k=2*m;
	d=k/2;
	if (k%2!=0) d++;
	l=k%2;
	if (l==0) l=2;
	lr=l%2; l=(l+1)/2;
	o=kk/(2*m);
	if (kk%(2*m)==0) o--;
	printf("%d %d ",l+o,d);
	if (lr==0) printf("R"); else printf("L");
	return 0;
}