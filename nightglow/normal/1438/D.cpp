#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
#include<map>
#include<iostream>

#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define N 100005

using namespace std;

int n,a[N],i,j,p,k,m,counter;

int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%d",&a[i]),a[0]^=a[i];
	if (n%2==0&&a[0]!=0) puts("NO");
	else
	{
		puts("YES");
		for (i=3;i<=n;i+=2) counter++;
		for (j=1;j<n-(n%2==0);j+=2) counter++;
		printf("%d\n",counter);
		for (i=3;i<=n;i+=2) printf("%d %d %d\n",i-2,i-1,i); 
		for (j=1;j<n-(n%2==0);j+=2) printf("%d %d %d\n",j,j+1,n);
	}
}