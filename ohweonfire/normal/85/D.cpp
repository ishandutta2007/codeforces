#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100005;
int n,a[maxn],size,op;
char s[10];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		if(s[0]=='s')
		{
			long long t=0;
			for(int i=2;i<size;i+=5)
				t+=a[i];
			printf("%I64d\n",t);
		}
		else if(s[0]=='d')
		{
			scanf("%d",&op);
			int k=lower_bound(a,a+size,op)-a;
			size--;
			for(int i=k;i<size;i++)a[i]=a[i+1];
		}
		else
		{
			scanf("%d",&op);
			int k=lower_bound(a,a+size,op)-a;
			size++;
			for(int i=size-1;i>k;i--)
				a[i]=a[i-1];
			a[k]=op;
		}
	}
	return 0;
}