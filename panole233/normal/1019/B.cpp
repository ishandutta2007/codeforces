#include<cstdio>
#include<cstring>

#define ff fflush(stdout)

int n,a[100001];

void work(int l,int r)
{
	if (l>r) {printf("! -1\n"); ff; return;}
	int mid=(l+r)>>1;
	if (l==mid) {printf("! -1\n"); ff; return;}
	printf("? %d\n",mid); ff; scanf("%d",&a[mid]);
	printf("? %d\n",mid+n/2); ff; scanf("%d",&a[mid+n/2]);
	if (a[mid]==a[mid+n/2]) {printf("! %d\n",mid); ff; return;}
	if ((a[l]<a[l+n/2]&&a[mid]>a[mid+n/2]||a[l]>a[l+n/2]&&a[mid+n/2]>a[mid])) work(l,mid);
	else work(mid,r);
}

int main()
{
	scanf("%d",&n);
	if (n%4!=0) {printf("! -1\n"); ff; return 0;}
	printf("? %d\n",n/2); ff; scanf("%d",&a[n/2]);
	printf("? %d\n",n); ff; scanf("%d",&a[n]);
	if (a[n]==a[n/2]) {printf("! %d\n",n/2); ff; return 0;}
	a[0]=a[n]; work(0,n/2);
	return 0;
}